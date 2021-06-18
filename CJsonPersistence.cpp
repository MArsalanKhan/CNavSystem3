//***************************************************************************
//*============= Copyright by Darmstadt University of Applied Sciences =======
//****************************************************************************

// System Headers

using namespace std;

// Own Headers
// Implementation
#include "CJsonPersistence.h"
#include <stdlib.h>

CJsonPersistence::CJsonPersistence()
{
}

void CJsonPersistence::setMediaName(string name)
{

	MyfileName = name;

}

void CJsonPersistence::Extract(string &type, string &value)
{
	value = type.substr(type.find(' ') + 1);
	type = type.substr(0, type.find(':'));
	for (unsigned int i = 0; i < value.length(); i++)
		value[i] = tolower(value[i]);
}

string CJsonPersistence::ExtractName(string &s1)
{
	int comma_pos1;
	//	comma_pos1 = aline.find(';', 0); // find where comma is starting from the beginning of aline
	// string name = aline.substr(0, comma_pos1);
	string s2 = s1.substr(s1.find(':', 0) + 1, s1.length());
	return s2;
}

string CJsonPersistence::GetTypeName(APT::CJsonToken::TokenType &type)
{
	string T;
	switch (type)
	{

	case 0:
		T = "begin_object";
		break;
	case 1:
		T = "end_object";
		break;
	case 2:
		T = "begin_array";
		break;
	case 3:
		T = "end_array";
		break;
	case 4:
		T = "name_separator";
		break;
	case 5:
		T = "value_separator";
		break;
	case 6:
		T = "string";
		break;
	case 7:
		T = "number";
		break;
	case 8:
		T = "bool";
		break;
	case 9:
		T = "null";
		break;
	}
	return T;
}

bool CJsonPersistence::writeData(const CWpDatabase& waypointDb,
		const CPoiDatabase& poiDb)
{
	string FileName = MyfileName;

	ofstream MyFile(FileName.c_str());
	CWpDatabase wpObj = waypointDb;

	map<string, CWaypoint> Mymap;
	wpObj.getMapWaypoiDatabase(Mymap);

	string name;
	double latitude, longitude;
	map<string, CWaypoint>::iterator i = Mymap.begin();
	map<string, CWaypoint>::iterator it2 = (++i);

	if (MyFile.is_open())
	{
		MyFile << "{\n\  \"waypoints\":  [" << endl;
		--i;
		i->second.getAllDataByReference(name, latitude, longitude);

		for (; i != Mymap.end(); ++i)
		{
			i->second.getAllDataByReference(name, latitude, longitude);

			if (it2 != Mymap.end())
			{
				// i->second.getAllDataByReference(name, latitude, longitude);

				// i is last
				MyFile << "\t{\n\t  \"name\": \"" << name << "\"," << "\n\t  "
						<< "\"latitude\": " << latitude << ",\n\t  "
						<< "\"longitude\": " << longitude << "\n\t}," << endl;
				++it2;

			}
		}
//i = Mymap.begin();
		--i;
		i->second.getAllDataByReference(name, latitude, longitude);

		MyFile << "\t{\n\t  \"name\": \"" << name << "\"," << "\n\t  "
				<< "\"latitude\": " << latitude << ",\n\t  "
				<< "\"longitude\": " << longitude << "\n\t}" << endl;

		MyFile << " ]," << endl;
		MyFile << " \"pois\":  [" << endl;

		map<string, CPOI> MyCPOImap;
		CPoiDatabase PCOI = poiDb;
		PCOI.getMapCpoiDatabase(MyCPOImap);
		string namePOI, description;
		t_poi type;
		double latitudePOI, longitudePOI;
		map<string, CPOI>::iterator i2 = MyCPOImap.begin();
		map<string, CPOI>::iterator it3 = (++i2);

		--i2;

		for (; i2 != MyCPOImap.end(); i2++)
		{

			if (it3 != MyCPOImap.end())
			{
				(i2->second).getAllDataByReference(namePOI, latitudePOI,
						longitudePOI, type, description);
				string Type = (i2->second).getType(type);
				MyFile << "\t{\n\t  \"name\": \"" << namePOI << "\","
						<< "\n\t  " << "\"latitude\": " << latitudePOI
						<< ",\n\t  " << "\"longitude\": " << longitudePOI
						<< ",\n\t  " << "\"type\": \"" << Type << "\",\n\t  "
						<< "\"description\": \"" << description << "\"\n\t},"
						<< endl;

			}
			++it3;

		}
		--i2;
		(i2->second).getAllDataByReference(namePOI, latitudePOI, longitudePOI,
				type, description);

		string Type = (i2->second).getType(type);
		MyFile << "\t{\n\t  \"name\": \"" << namePOI << "\"," << "\n\t  "
				<< "\"latitude\": " << latitudePOI << ",\n\t  "
				<< "\"longitude\": " << longitudePOI << ",\n\t  "
				<< "\"type\": \"" << Type << "\",\n\t  "
				<< "\"description\": \"" << description << "\"\n\t}" << endl;
		MyFile << "  ]" << endl;
		MyFile << "\}" << endl;

		return true;
		MyFile.close();

	}
	else
	{
		cout << " Unable to open the file " << endl;
		exit(1);
		return false;
	}

	return true;

}

bool CJsonPersistence::readData(CWpDatabase& waypointDb, CPoiDatabase& poiDb,
		MergeMode mode)
{

//std::map<string,CWaypoint> CWayContainer;
//	CWayContainer.insert(pair<string, CWaypoint>(poi.getName(), poi));
	APT::CJsonToken *MyToken;
	APT::CJsonToken::State current_state =
			APT::CJsonToken::Waiting_for_first_token;
//APT::CJsonToken::TokenType current_event = APT::CJsonToken::BEGIN_OBJECT;

	string FileName = MyfileName;

	ifstream MyFile(FileName.c_str());
	map<string, CWaypoint> WayPoiFileContainer;
			map<string, CPOI> CPoiFileContainer;
	vector<string> NumberofAtributes;
//map<string, CWaypoint> WayPoiFileContainer;
	if (MyFile.is_open())
	{
		cout << "  FILE Successfuly opened" << endl;
		APT::CJsonScanner MyScanner(MyFile);
		//while (MyScanner.nextToken()!=0)

		string attributeName, Name, Type, Description;
		double longitude, Latitude;
		bool po = true;
		while (po)
		{

			//cout<<"MyToken1.str()"<<MyToken1.str()<<endl;
			//	MyToken1=new CJsonToken;
			string Token, TokenBase;
			//CJsonToken::str();
			MyToken = MyScanner.nextToken();
			Token = MyToken->str();
			APT::CJsonToken::TokenType type;
			type = MyToken->getType();
			string token = GetTypeName(type);
			//cout<< " a = "<<a<<endl;
			//string s=C.GetTypeName(b);
			//GetTypeName(APT::CJsonToken::BEGIN_OBJECT);

			//cout<<a;
			//string b=ExtractName(Token);
			//	cout<< " B "<<b<<endl;
			//	cout << " TOKEN IS " << Token << endl;

			switch (current_state)
			{
			case APT::CJsonToken::Waiting_for_first_token:

				if (token == "begin_object")
				{
					cout << " NOW TOKEN IS1 " << Token << endl;

					current_state = APT::CJsonToken::Waiting_for_db_name;

				}
				break;

			case APT::CJsonToken::Waiting_for_db_name:
				if (token == "string")
				{
					current_state =
							APT::CJsonToken::Waiting_for_name_db_separator;
					cout << " NOW TOKEN IS2 " << Token << endl;

					//cout << " TOKEN IS " << Token << endl;
					//  APT::CJsonStringToken TokenNumber(MyToken->str());
					//	cout <<"value : "<< TokenNumber.getValue()<<endl;

					string DBName = ExtractName(Token);
					cout << "name of Database " << DBName << endl;
				}
				break;

			case APT::CJsonToken::Waiting_for_name_db_separator:
				if (token == "name_separator")
				{
					cout << " NOW TOKEN IS3 " << Token << endl;

					current_state = APT::CJsonToken::Waiting_for_db_begin;
				}
				break;

			case APT::CJsonToken::Waiting_for_db_begin:

				if (token == "begin_array")
				{
					cout << " NOW TOKEN IS4 " << Token << endl;

					current_state = APT::CJsonToken::waiting_for_object;
				}
				break;

			case APT::CJsonToken::waiting_for_object:
				if (token == "begin_object")
				{
					cout << " NOW TOKEN IS5 " << Token << endl;

					current_state = APT::CJsonToken::Waiting_for_attribute_name;
				}
				break;

			case APT::CJsonToken::Waiting_for_attribute_name:
				if (token == "string")
				{
					cout << " NOW TOKEN IS6 " << Token << endl;
					attributeName = ExtractName(Token);
					cout << "attributeName" << attributeName << endl;
					current_state =
							APT::CJsonToken::Waiting_for_name_object_separator;
					//To do : store attribute name
					//cout << " TOKEN IS " << Token << endl;
					//APT::CJsonStringToken TokenNumber(MyToken->str());
					//cout << TokenNumber.getValue();
					// string S=TokenString-><string,string>getValue();
				}
				break;

			case APT::CJsonToken::Waiting_for_name_object_separator:
				if (token == "name_separator")
				{
					cout << " NOW TOKEN IS7 " << Token << endl;

					current_state =
							APT::CJsonToken::Waiting_for_attribute_value;
				}
				break;

			case APT::CJsonToken::Waiting_for_attribute_value:
				if (token == "string" || token == "number")
				{
					cout << " NOW TOKEN IS8 " << Token << endl;
					cout<<" token IS8 is "<<token<<endl;
					if (token == "string")
					{
						string PointName = ExtractName(Token);
						cout << " PointName : " << PointName << endl;
						if (attributeName == "name")
						{
							Name = attributeName;
							NumberofAtributes.push_back(Name);
							cout << " name : " << attributeName << endl;

						}
						if (attributeName == "type")
						{
							Type = attributeName;
							NumberofAtributes.push_back(Type);
							cout << " type : " << attributeName << endl;


						}
						if (attributeName == "description")
						{
							Description = attributeName;
							NumberofAtributes.push_back(Description);
							cout << " description : " << attributeName << endl;


						}

					}
					if (token == "number")
					{
						string Coordinate = ExtractName(Token);
cout<<"Thr token is number but no attribute name "<<" attributeName : "<<attributeName<<endl;
						if (attributeName == "latitude")
						{
							Latitude = atof(Coordinate.c_str());
							NumberofAtributes.push_back(Coordinate);
							cout << " Latitude : " << Latitude << endl;


						}
						else // (attributeName == "longitude")
						{
							longitude = atof(Coordinate.c_str());
							NumberofAtributes.push_back(Coordinate);
							cout << " longitude : " << longitude << endl;


						}

						//cout << " Coordinate : " << Coordinate << endl;
					}
					int i=NumberofAtributes.size();
					switch(i){
					case 3:

					WayPoiFileContainer.insert(pair<string, CWaypoint>(Name,CWaypoint(Name, Latitude,longitude)));

					case 5:
						t_poi CType;
						CPersistentClass *Ca;
						CType=Ca->getType(Type);
				   CPoiFileContainer.insert(pair<string, CPOI>(Name,CPOI(CType , Name,Description, Latitude,longitude)));


					}
					//WayPoiFileContainer.insert(pair<string, CWaypoint>(name,CWaypoint(Name, Latitude,longitude)));
						//CPoiFileContainer.insert(pair<string, CPOI>(name,CPOI(Type, name,Description, Latitude,longitude)));

				}

				current_state = APT::CJsonToken::Waiting_for_value_separator;
				//To do : assign value accoding to stored attribute name
				//string HI = MyToken->str();
				//cout << " HI " << MyToken->str() << endl;
				//double n = atof(MyToken->str().c_str());
				//APT::CJsonNumberToken TokenNumber(atof(MyToken->str()));
				//cout<<TokenNumber.getValue();
//
				break;

			case APT::CJsonToken::Waiting_for_value_separator:
				if (token == "value_separator")
				{
					cout << " NOW TOKEN IS9 " << Token << endl;

					current_state = APT::CJsonToken::Waiting_for_attribute_name;

				}
				if (token == "end_object")
				{
					current_state = APT::CJsonToken::Waiting_for_next_object;
					cout << " NOW TOKEN IS10 " << Token << endl;

				}
				break;

			case APT::CJsonToken::Waiting_for_next_object:
				if (token == "end_array")
				{
					cout << " NOW TOKEN IS11 " << Token << endl;

					current_state = APT::CJsonToken::Waiting_for_db_end;
				}
				if (token == "value_separator")
				{
					current_state = APT::CJsonToken::waiting_for_object;
					cout << " NOW TOKEN IS12 " << Token << endl;

				}
				break;
			case APT::CJsonToken::Waiting_for_db_end:
				if (token == "end_object")
				//To do : end the loop , the input is exhasted
				{
					cout << " Byebye" << endl;
					po = false;
				}
				if (token == "value_separator")
				{
					cout << " NOW TOKEN IS13 " << Token << endl;

					current_state = APT::CJsonToken::Waiting_for_db_name;
					cout << " Return Again" << endl;
				}
				break;
			default:
				po = false;
			}

		}
	}

	switch (mode)
		{
		case MERGE:
			waypointDb.MergeWaypoiContainer(WayPoiFileContainer, "MERGE");
			poiDb.MergeCpoiContainer(CPoiFileContainer, "MERGE");

			break;
		case REPLACE:
			waypointDb.MergeWaypoiContainer(WayPoiFileContainer, "REPLACE");
			poiDb.MergeCpoiContainer(CPoiFileContainer, "REPLACE");

			break;
		}
	return 0;

}
