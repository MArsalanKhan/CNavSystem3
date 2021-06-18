/*
 * CJSonPersistance.cpp
 *
 *  Created on: 07.01.2016
 *      Author: Arsalan
 */

#include "CJSonPersistance.h"

//CJSonPersistance::CJSonPersistance()
//{
//	// TODO Auto-generated constructor stub
//
//}
//
//CJSonPersistance::~CJSonPersistance()
//{
//	// TODO Auto-generated destructor stub
//}



void CJSonPersistance::setMediaName(string name)

{
	myfilename=name;

}

bool CJSonPersistance:: writeData (const cWpDatabase& waypointDb,const CPoiDatabase& poiDb)

{
  //unsigned int check=0;
  string cwp=myfilename+"-.txt";

		  ofstream myFile;
			   myFile.open(cwp.c_str());
			   if(myFile.is_open())
			   {

		    map<string,cWaypoint> myWpMap;
		    cWpDatabase wp=waypointDb;
		    myWpMap=wp.getMapDataBaseWpPoi();



				   string name;
				   double latitude;
				   double longitude ;

				   map<string,cWaypoint> :: iterator it1=myWpMap.begin();
				  // map<string, cWaypoint>::iterator i1 = (++it1);
				  // --it1;
				   myFile << "{\n\  \"waypoints\":  [" << endl;

				 for(;it1!=myWpMap.end();++it1)
				   {


				   	name= it1->second.getName();
				   	latitude=it1->second.getLatitude();
				   	longitude=it1->second.getLongitude();
					myFile << "\t{\n\t  \"name\": \"" << name << "\"," << "\n\t  "<< "\"latitude\": " << latitude << ",\n\t  "<< "\"longitude\": " << longitude << "\n\t}";
				   	it1++;

				   	if(it1!=myWpMap.end())
				   	{
                      myFile<<","<<endl;

				   	}
				   	else
				   	{
				   		myFile<<endl;
				   	}
                        it1--;
				   	}


				 myFile << " \n ]," << endl;
				 		myFile << " \"pois\":  [" << endl;


                 	map<string,CPOI> myPOIMap;
			   				CPoiDatabase CPOI1=poiDb;
			   				myPOIMap=CPOI1.getMapDataBaseWpPoi();
//			   				string name;
//			   				double latitude;
//			   				double longitude ;
			   			string description;
			   				string type;
			   				map<string,CPOI>::iterator it2=myPOIMap.begin();
			   				//map<string,CPOI>::iterator i2=(++it2);
			   				//--it2;


			   				cout<<"{ \n"<<endl;
//			   				cout<<"pois : ["<<endl;
//			   				cout<<"{"<<endl;
			   			 for(;it2!=myPOIMap.end();++it2)
			   			{
			   		    type=it2->second.getType();
			   		    description=it2->second.getDescription();
			   			name= it2->first;
			   			latitude=it2->second.getLatitude();
			   			longitude=it2->second.getLongitude();
			   			myFile << "\t{\n\t  \"name\": \"" << name << "\","<< "\n\t  " << "\"latitude\": " << latitude<< ",\n\t  " << "\"longitude\": " << longitude;
			   			    myFile << ",\n\t  " << "\"type\": \"" << type << "\",\n\t  ";
			   			myFile<< "\"description\": \"" << description << "\"\n\t}";
			   			it2++;
			   			if(it2!=myPOIMap.end())
			   			{
			   				myFile<<","<<endl;

			   			}

			   			else
			   			{
			   				myFile<<endl;
			   			}
			   		 --it2;

			   			}

            		 myFile<<" \n ] \n }"<<endl;
			   			return true;
			   			myFile.close();




			   			}

			   			else
			   				{cout<<"Unable to open the file"<<endl;
			   				return false;
			   				}

  return true;
}
bool CJSonPersistance::readData(cWpDatabase& waypointDb, CPoiDatabase& poiDb,MergeMode mode)
{

// using  the mode if it is replace mode than both of the last databases are cleared else use mergemode by default
	if (mode == REPLACE)
	{
		waypointDb.clearDB();
		poiDb.clearDB();
	}
	string cwp=myfilename+"-.txt";
	ifstream myFile;
	myFile.open(cwp.c_str());
	if (myFile.is_open())
	{
		// giving our file to JsonScanner in order to scan it
		APT::CJsonScanner myScan(myFile);
		// since Jsonscanner returns the pointer to the next token so declaring a pointer of type CJsontoken
			APT::CJsonToken* pointer_Token;

			// string declared to get the name of the token
			string stringvalueoftoken;
			// enum for token type
			APT::CJsonToken::TokenType my_Token_Type;
			//enum for current states
			States currentState;
			string DBName,AttributeName,currentName,currentType,currentDescription;
			double Latitudevalue,Longitudevalue;
			currentState = Waiting_for_first_token_OR_idle_state;
			try {
			pointer_Token = myScan.nextToken();
			}//get the pointer point to next token

			catch(string &illegalChar)
			{
		cout<<"There occurred an exception at:"<<myScan.scannedLine()<<"and the character is:"<<pointer_Token->getType();
			}
		bool dbF = false;
		while (dbF==false && (pointer_Token!=0))
		{


			// getting the token type with the function calling getType
				my_Token_Type = pointer_Token->getType(); // i.e getting the type of the token
				// getting string for the next token
				stringvalueoftoken = pointer_Token->str();

				// to subtract "stringpart" from the
			stringvalueoftoken=stringvalueoftoken.substr(stringvalueoftoken.find(':', 0) + 2, stringvalueoftoken.length());

    // switching the states

			switch (currentState)
			{
			case Waiting_for_first_token_OR_idle_state:
				if (my_Token_Type == APT::CJsonToken::BEGIN_OBJECT)
				{
					currentState = Waiting_for_db_name;
				}

				else
				{
					cout<<"Database could not be opened due to wrong input"<<endl;
				}
				break;
			case Waiting_for_db_name:
				if (my_Token_Type == APT::CJsonToken::STRING)
				{
					currentState = Waiting_for_DB_name_separator;

					// getting the name of the database and storing it
					DBName = stringvalueoftoken;
				}

				else
				{
				cout<<"not getting the name of database  "<<endl;
				}
				break;

			case Waiting_for_DB_name_separator:
				if (my_Token_Type == APT::CJsonToken::NAME_SEPARATOR)
				{
					// getting the name separator ":" now waiting for data base to begin
					currentState = Waiting_for_db_begin;
				}
				break;
			case Waiting_for_db_begin:
				if (my_Token_Type == APT::CJsonToken::BEGIN_ARRAY)
				{
					// data base beging token "[" got now waiting for object to come
					currentState = Waiting_for_object;
				}
				break;
			case Waiting_for_object:
				if (my_Token_Type == APT::CJsonToken::BEGIN_OBJECT)
				{
					// the token begin object "{" is got now  expecting the name of the first attribute of the object
					currentState = Waiting_for_attribute_name;
				}
				break;
			case Waiting_for_attribute_name:
				if (my_Token_Type == APT::CJsonToken::STRING)
				{
					// getting the name of the attribute and storing it,
					AttributeName=stringvalueoftoken;
					// getting the name of the attribute ""  and now waiting for name separator

					currentState = Waiting_for_object_name_separator;
				}
				break;
			case Waiting_for_object_name_separator:
		//		cout << stringvalueoftoken << endl;
				if (my_Token_Type == APT::CJsonToken::NAME_SEPARATOR)
				{ // got the token nameseparator and now expecting attribute value either number or string
					currentState = Waiting_for_attribute_value;
				}
				break;
			case Waiting_for_attribute_value:
					if (my_Token_Type == APT::CJsonToken::STRING)
				{
						currentState = Waiting_for_value_separator;

						// now storing the value of respective attributes into their respective places
					if (AttributeName=="name")
					{
						// assigning the value of the attribute to the string
						currentName=stringvalueoftoken;
					}
					if (DBName=="pois")
					{
						if(AttributeName=="description")
						{
							// if attribute value is description assigning it to the description string
							currentDescription=stringvalueoftoken;
						}

						else if(AttributeName=="type")
						{
							// if attribute value is type assigning it to the description string
							currentType=stringvalueoftoken;
						}
					}

					}

					else if(my_Token_Type==APT::CJsonToken::NUMBER)
					{
						currentState=Waiting_for_value_separator;
					//checking the attribute name
						if(AttributeName=="latitude")
						{    // converting the value into double in case of latitude
							Latitudevalue=atof(stringvalueoftoken.c_str());
						}

						else if(AttributeName=="longitude")
						{
							// converting the value into double in case of longitude
							Longitudevalue=atof(stringvalueoftoken.c_str());
						}
					}

					break;

			case Waiting_for_value_separator:
			//	currentState = Waiting_for_next_object;
				if (my_Token_Type  == APT::CJsonToken::VALUE_SEPARATOR){
     // if value separator is got, means we are still in the same database and again going to the state waiting for attribute name
					currentState= Waiting_for_attribute_name;
				}
				else if (my_Token_Type == APT::CJsonToken::END_OBJECT)
				{
					// if end object is got then saving then its time to save the object inside database
                          currentState=Waiting_for_next_object;

					if (DBName=="waypoints"){
						//cout << currentName << "\n" << Latitudevalue << "\n" << Longitudevalue ;
						// creating a temporary object cwaypoint
						cWaypoint myWpObj(currentName,Latitudevalue,Longitudevalue);
					// adding the gotwaypoint inside the database
						waypointDb.addWaypoint(myWpObj);
					}
					else if (DBName=="pois")
					{


						//currentType=obj.getType();

						//cout << currentName << "\n" << Latitudevalue << "\n" << Longitudevalue << "\n" << currentDescription<< "\n" << currentType;
					//checking the current type to get CPOI
						if (currentType== "Resturant")
						{
							CPOI myPOIobj(RESTURANT,currentName,currentDescription,Latitudevalue,Longitudevalue);
							poiDb.addPoi(myPOIobj);
						}
						else if (currentType== "University")
						{
							CPOI myPOIobj(UNIVERSITY,currentName,currentDescription,Latitudevalue,Longitudevalue);
							poiDb.addPoi(myPOIobj);

						}

                   }

				}

				break;

			case Waiting_for_next_object:
				if (my_Token_Type  == APT::CJsonToken::VALUE_SEPARATOR)
				{    // if the array of objects is still cotinued
					currentState= Waiting_for_object;
				}
				else if (my_Token_Type == APT::CJsonToken::END_ARRAY)
				{    // if array ends then waiting for DB end
					currentState = Waiting_for_db_end;
				}
				break;

			case Waiting_for_db_end:
			//	cout << stringvalueoftoken << endl;
				if (my_Token_Type  == APT::CJsonToken::VALUE_SEPARATOR)
				{    // getting value separator in state DB end , now we are entering into a new database
					currentState= Waiting_for_db_name;
				}
				else if(my_Token_Type  == APT::CJsonToken::END_OBJECT)
				{
					// if we get end object token "}" then file need to be closed
					cout << "File end" ;
					// coming out of the loop
					dbF=true;
				}

			     else
					dbF=true;
				break;

			default:
				dbF=true;
				break;

			}
			// getting the next token at end of each state
			try {
				pointer_Token = myScan.nextToken();
				}//get the pointer point to next token

			catch(string &illegalChar)
					{
					cout<<"There occurred an exception at:"<<myScan.scannedLine()<<"and the character is:"<<pointer_Token->getType();
					}
		}
		myFile.close();

	}
	else
	{
		cout << "Could not open the file " << endl;
		return false;
	}

	return true;
}








