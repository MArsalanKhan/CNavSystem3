/*
 * CPersistentClass.cpp
 *
 *  Created on: Dec 7, 2015
 *      Author: abd sharaf
 */

#include "CPersistentClass.h"
#include <locale>
#include<vector>
#include <stdlib.h>
#include <string.h>
#include <sstream>
CPersistentClass::CPersistentClass()
{
	// TODO Auto-generated constructor stub

}

CPersistentClass::~CPersistentClass()
{
	// TODO Auto-generated destructor stub
}
void CPersistentClass::setMediaName(string name)
{
	MyfileName = name;
}

bool CPersistentClass::writeData(const CWpDatabase& waypointDb,
		const CPoiDatabase& poiDb)
{

	// writing wayPoint in our file

	string FileName = MyfileName + "-wp.txt";

	ofstream MyFile(FileName.c_str());
	CWpDatabase wpObj = waypointDb;

	map<string, CWaypoint> Mymap;
	wpObj.getMapWaypoiDatabase(Mymap);

	string name;
	double latitude, longitude;
	map<string, CWaypoint>::iterator i = Mymap.begin();
	if (MyFile.is_open())
	{

		for (; i != Mymap.end(); i++)
		{
			i->second.getAllDataByReference(name, latitude, longitude);
			MyFile << name << ";" << latitude << ";" << longitude << endl;
		}

		MyFile.close();

	}
	else
	{
		cout << " Unable to open the file " << endl;
	}

	FileName = MyfileName + "-poi.txt";

	MyFile.open(FileName.c_str());

// writing Point of interest in our file

	map<string, CPOI> MyCPOImap;
	CPoiDatabase PCOI = poiDb;
	PCOI.getMapCpoiDatabase(MyCPOImap);
	string namePOI, description;
	t_poi type;
	double latitudePOI, longitudePOI;
	map<string, CPOI>::iterator i2 = MyCPOImap.begin();

	if (MyFile.is_open())
	{

		for (; i2 != MyCPOImap.end(); i2++)
		{

			(i2->second).getAllDataByReference(namePOI, latitudePOI,
					longitudePOI, type, description);
			string Type = (i2->second).getType(type);
			MyFile << Type << ";" << namePOI << ";" << description << ";"
					<< latitudePOI << ";" << longitudePOI << endl;
		}

		MyFile.close();
		return true;

	}
	else
	{
		cout << " Unable to open the file " << endl;
		exit(1);
		return false;
	}

	return true;

}

bool CPersistentClass::readData(CWpDatabase& waypointDb, CPoiDatabase& poiDb,
		MergeMode mode)
{
	cout << " FIRST READING Way POINTS" << endl;
	string FileName = MyfileName + "-wp.txt";

	ifstream MyFile(FileName.c_str());

	map<string, CWaypoint> WayPoiFileContainer;

	if (MyFile.is_open())
	{
		cout << " Cwaypoint FILE Successfuly opened" << endl;
		while (!MyFile.eof())
		{
			string aline;
			int numline = 0;
			int NumofSemiColon = 0;
			while (getline(MyFile, aline)) // reads line from our file

			{
				NumofSemiColon = 0;

				istringstream CSVStream(aline);
				string LineStringElement;
				char delim = ';';
				vector<string> CSVColumn;

				if (aline.empty())
				{
					++numline;

					cout << "Line number " << numline << " is empty" << endl;

					continue;
				}
				for (unsigned int n = 0; n < aline.length(); n++)
				{
					if (aline.at(n) == ';')
					{
						++NumofSemiColon;
					}

				}
				if (NumofSemiColon != 2)
				{
					cout << "Expected semicolon but not found for CWaypoint at line number [" << ++numline <<"]"<< endl;
					NumofSemiColon = 0;
					--numline;
					//if (aline.find(';') != string::npos){delim=';';
				}
				// declare a stream input object to read elements in each line one by one
					while (getline(CSVStream, LineStringElement, delim))
					{
						CSVColumn.push_back(LineStringElement);
					}
					numline++;
					if (CSVColumn.size() == 3)
					{
						vector<string>::iterator j = CSVColumn.begin();

						//check if Latitude and Longitude are of double type
						if (is_double(*(j + 1)) && is_double(*(j + 2)))
						{
							if ((*j).empty())
								cout << " Name is empty in line number "
										<< numline << endl;
							else

							{
								string FLatitude = *(j + 1);
								string FLongitude = *(j + 2);
								string name = (*j);
								double DLatitude = atof(FLatitude.c_str()); //convert string to double - latitude

								double DLongitude = atof(FLongitude.c_str()); //convert string to double - longitude

								//insert longitude and latitude values in a buffer container
								WayPoiFileContainer.insert(
										pair<string, CWaypoint>(name,
												CWaypoint((*j), DLatitude,
														DLongitude)));

							}

						}
						else
						{
							cout
									<< "ERROR Latitude and Longitude must be numerical values for Waypoint in Line number <"
									<< numline << ">" << " : <";
							for (vector<string>::iterator i1 =
									CSVColumn.begin(); i1 != CSVColumn.end();
									i1++)
							{
								cout << (*i1) << delim;
							}
							cout << ">" << endl;
						}

					}
					else
					{
						if (CSVColumn.size() < 3)
							cout << "Error: Too few fields in line<"
									<< (numline) << "> : <";
						else
							cout << "Error: Too many fields in line<"
									<< (numline) << "> : <";
						for (vector<string>::iterator i1 = CSVColumn.begin();
								i1 != CSVColumn.end(); i1++)
						{
							cout << (*i1) << delim;

						}
						cout << ">" << endl;
					}
				}

		}
		MyFile.close();

	}
	else
	{
		cout << " Unable to open the file " << endl;
		return false;
	}

	/*
	 Reading POI file
	 */

	string CPOIFileName = MyfileName + "-poi.txt";

	MyFile.open(CPOIFileName.c_str());

	map<string, CPOI> CPoiFileContainer;//declare a buffer container

	if (MyFile.is_open())
	{
		cout << " <CPOI FILE successfuly opened> " << endl;
		while (!MyFile.eof())
		{
			string aline;
			int Cnumline = 0;
            int CNumofSemiColon=0;
			while (getline(MyFile, aline)) // reads line from our file

			{
				CNumofSemiColon=0;
				istringstream CSVStream(aline);// declare a stream input object to read elements in each line one by one
				string LineStringElement;// declare string buffer
				char delim = ';';
				vector<string> CSVColumn;
				if (aline.empty())
				{
					++Cnumline;
					cout << "Line number " << Cnumline << " is empty" << endl;
					continue;
				}
				for (unsigned int n = 0; n < aline.length(); n++)
								{
									if (aline.at(n) == ';')
									{
										++CNumofSemiColon;
									}

								}
								if (CNumofSemiColon != 4)// Check for the number of semicolon
								{
									cout << "Expected semicolon but not found for CPOI  at line number [" <<++Cnumline <<"]"<< endl;
									CNumofSemiColon = 0;
									--Cnumline;
									//if (aline.find(';') != string::npos){delim=';';

								}
				while (getline(CSVStream, LineStringElement, delim))// read until a delimitating char is encountered then push element in the Vector
				{
					CSVColumn.push_back(LineStringElement);
				}
				++Cnumline;
				if (CSVColumn.size() == 5)
				{
					vector<string>::iterator j = CSVColumn.begin();
					//check if Latitude and Longitude are of double type
					if (is_double(*(j + 3)) && is_double(*(j + 4)))//check if longitude and latitude are of double type
					{
						if ((*j).empty())
							cerr << " Name is empty in line number " << Cnumline
									<< endl;
						else

						{
							string Type = (*j);
							string name = *(j + 1);
							string description = *(j + 2);
							string Flatitude = *(j + 3);
							string Flongitude = *(j + 4);
							double DLatitude = atof(Flatitude.c_str()); //convert string to double - Latitude

							double DLongitude = atof(Flongitude.c_str()); //convert string to double - longitude

							//insert latitude and longitude values in the buffer container
							CPoiFileContainer.insert(
									pair<string, CPOI>(name,
											CPOI(this->getType(Type), name,
													description, DLatitude,
													DLongitude)));

						}

					}
					else
					{
						cout
								<< "ERROR Latitude and Longitude must be numerical values for Cpoi in Line number < "
								<< Cnumline << ">" << " : <";
						for (vector<string>::iterator i1 = CSVColumn.begin();
								i1 != CSVColumn.end(); i1++)
						{
							cout << (*i1) << delim;
						}
						cout << ">" << endl;
					}

				}
				else
				{
					if (CSVColumn.size() < 5)
						cout << "Error: Too few fields in line<" << (Cnumline)
								<< "> ";
					else
						cout << "Error: Too many fields in line<" << (Cnumline)
								<< "> : < ";
					for (vector<string>::iterator i1 = CSVColumn.begin();
							i1 != CSVColumn.end(); i1++)
					{
						cout << (*i1) << delim;

					}
					cout << ">" << endl;
				}
			}
		}
		MyFile.close();

	}
	else
	{
		cout << " Unable to open the file " << endl;
		return false;
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
	return true;

}
bool CPersistentClass::is_double(const string& s)
{
	istringstream iss(s);
	double d;
	char c;
	return iss >> d && !(iss >> c);
}
t_poi CPersistentClass::getType(string& Type) const
{
	t_poi type;
	if (Type == "RESTAURANT")
		type = RESTAURANT;

	else if (Type == "HOTEL")

		type = HOTEL;
	else if (Type == "UNIVERSITY")

		type = UNIVERSITY;
	else
		type = None;

	return type;
}
//read file prototype
//bool CPersistentClass::readData(CWpDatabase& waypointDb, CPoiDatabase& poiDb,
//		MergeMode mode)
//{
//	string FileName = MyfileName + "-wp.txt";
//
//	ifstream MyFile(FileName.c_str());
//
//	map<string, CWaypoint> Filecontainer;
//
//	if (MyFile.is_open())
//	{
//		cout << "successfuly opened" << endl;
//		while (!MyFile.eof())
//		{
//			string aline;
//			int numline=;
//			while (getline(MyFile, aline)) // reads line from our file
//
//			{
//				if (aline.empty())
//				{
//					cout << "Line no." << numline << " is empty" << endl;
//					continue;
//				}
//				int comma_pos1;
//				comma_pos1 = aline.find(';', 0); // find where comma is starting from the beginning of aline
//				string name = aline.substr(0, comma_pos1);
//				int comma_pos2 = aline.find(';', comma_pos1);
//				//substr(start position,length from the postoion)
//				string FLatitude = aline.substr(comma_pos1 + 1, comma_pos2 - 1);
//				string Flongitude = aline.substr(comma_pos2 + 1,
//						aline.length() - comma_pos2 - 1);
//				double DLatitude = atof(FLatitude.c_str()); //convert string into double for latitude
//				double DLongitude = atof(Flongitude.c_str()); //same for longitude
//
//				Filecontainer.insert(
//						pair<string, CWaypoint>(name,CWaypoint(name, DLatitude, DLongitude)));
//				++numline;
//				//cout << Filecontainer[name];
//				cout<<"numline is "<<numline<<endl;
//			}
//
//		}
//		MyFile.close();
//	}
//	else
//	{
//		cout << " Unable to open the file " << endl;
//		return false;
//	}
//
//	cout << " Original" << endl;
//	switch (mode)
//	{
//	case MERGE:
//		waypointDb.MergeWaypoiContainer(Filecontainer, "MERGE");
//		break;
//	case REPLACE:
//		waypointDb.MergeWaypoiContainer(Filecontainer, "REPLACE");
//
//		break;
//	}
//	return true;
//
//}

