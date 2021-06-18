///*
// * CSVStorageComponent.cpp
// *
// *  Created on: 10.12.2015
// *      Author: DELL
// */
//
//#include "CSVStorageComponent.h"
//
//CSVStorageComponent::CSVStorageComponent()
//{
//	// TODO Auto-generated constructor stub
//
//}
//
//CSVStorageComponent::~CSVStorageComponent()
//{
//	// TODO Auto-generated destructor stub
//}
//
//void CSVStorageComponent::setMediaName(string name)
//
//{
//	myfilename=name;
//}
//
//bool CSVStorageComponent:: writeData (const cWpDatabase& waypointDb,const CPoiDatabase& poiDb)
//
//{
//
//  string cwp=myfilename+"-wp.txt";
//
//		  ofstream CSVWP;
//			   CSVWP.open(cwp.c_str());
//			   if(CSVWP.is_open())
//			   {
//
//		    map<string,cWaypoint> myWpMap;
//			waypointDb.GetmapWp(myWpMap);
//
//
//				   string name;
//				   double latitude;
//				   double longitude ;
//				   map<string,cWaypoint> :: iterator it;
//
//				   for(it=myWpMap.begin();it!=myWpMap.end();++it)
//				   {
//				   	name= it->second.getName();
//				   	latitude=it->second.getLatitude();
//				   	longitude=it->second.getLongitude();
//				    CSVWP<<name<<";"<<latitude<<";"<<longitude<<"\n";
//				   	}
//
//
//
//
//				CSVWP.close();
//
//
//				}
//
//				else
//				{cout<<"Unable to open the file"<<endl;
//				return false;
//				}
//
//			   string poi=myfilename+"-poi.txt";
//			   ofstream CSVPoi;
//			   			CSVPoi.open(poi.c_str());
//			   			if(CSVPoi.is_open())
//			   			{
//			   				map<string,CPOI> myPOIMap;
//			   				CPoiDatabase CPOI1=poiDb;
//			   				CPOI1.GetmapPoi(myPOIMap);
//			   				string name;
//			   				double latitude;
//			   				double longitude ;
//			   			string description;
//			   				string type;
//			   				map<string,CPOI>::iterator it;
//
//			   			 for(it=myPOIMap.begin();it!=myPOIMap.end();++it)
//			   			{
//			   		    type=it->second.getType();
//			   		    description=it->second.getDescription();
//			   			name= it->second.getName();
//			   			latitude=it->second.getLatitude();
//			   			longitude=it->second.getLongitude();
//			   			CSVPoi<<type<<";"<<description<<";"<<name<<";"<<latitude<<";"<<longitude<<"\n";
//
//			   			}
//
//
//			   			}
//
//			   			else
//			   				{cout<<"Unable to open the file"<<endl;
//			   				return false;
//			   				}
//
//    return true;
//
//}
//
//bool CSVStorageComponent:: readData (cWpDatabase& waypointDb, CPoiDatabase& poiDb,MergeMode mode)
//
//{
//	// in case of replace mode mode
//	if (mode == REPLACE)
//	{
//		// in order to replace,we need to clear databases first
//		waypointDb.clearDB();
//		poiDb.clearDB();
//		// declaring objects of ifstream
//		ifstream filem_wp;
//		ifstream filem_poi;
//		// initializing the line counters
//		int count_line1 = 0;
//		int count_line2 = 0;
//		// opening the file to be read from(here from cwaypointdatabase)
//		filem_wp.open((myfilename + "-wp.txt").c_str());
//		if (filem_wp.is_open())
//		{
//			// declaring a string
//			string CSVSt_line;
//			// reading the file with the help of getline function
//			while (getline(filem_wp, CSVSt_line))
//			{
//				//initializing the break for the line i.e ";"
//				char checkBreak = ' ';
//				//converting a string into a stream
//
//				istringstream CSVSt_stream(CSVSt_line);
//
//				//declaring a temporary vector
//
//				vector<string> CSVSt_wp_part;
//
//				// checking the line and either it contains the character ;
//
//				if (CSVSt_line.find(';') != string::npos)
//				{
//					checkBreak = ';';
//					cout << " ; is there" << endl;
//
//					string CSVSt_element;
//					// reading the stream until check break is found i.e getting the required fields
//					while (getline(CSVSt_stream, CSVSt_element, checkBreak))
//					{
//						// pushing the segments into the vector
//						CSVSt_wp_part.push_back(CSVSt_element);
//
//					}
//					// creating an iterator to iterate throughn the vector containing required fields
//					vector<string>::iterator i;
//					i = CSVSt_wp_part.begin();
//					// advancing to the next line
//					count_line1++;
//					// checking the number of elemnts inside the vector
//					if (CSVSt_wp_part.size() == 3)
//					{
//						cout << "It is a way point consisting 3 attributes"
//								<< endl;
//						vector<string>::iterator i;
//						i = CSVSt_wp_part.begin();
//
//						istringstream stTost(*(i + 1));
//						istringstream stTostt(*(i + 2));
//						double wp;
//						char c;
//						if ((stTost >> wp) && (stTostt >> wp))
//						{
//							//adding waypoint into the database
//							waypointDb.addWaypoint(
//									cWaypoint((*i), atof((*(i + 1)).c_str()),
//											atof((*(i + 2)).c_str())));
//						}
//						else if ((stTost >> c) && (stTostt >> c))
//						{
//
//							cout
//									<< "Coordiantes not be in the required format i.e erroroneous"
//									<< endl;
//						}
//					}
//
//				}
//				else
//				{
//					cout
//							<< "Error: format of file is not correct having no required fields ;"
//							<< endl;
//				}
//			}
//		}
//		// in case if the file is not opened
//		else
//		{
//			cout << "Error: file is not opened" << endl;
//			return false;
//		}
//
//		cout << "It is a POI object" << endl;
//		filem_poi.open((myfilename + "-poi.txt").c_str());
//		if (filem_poi.is_open())
//		{
//			// creating a string
//			string CSVSt_line;
//			//reading the line from the file
//			while (getline(filem_poi, CSVSt_line))
//			{
//				// the break point is initialized
//				char checkbreak = ' ';
//				//converting string to stream
//
//				istringstream CSVSt_stream(CSVSt_line);
//
//				// a temporary vector to store the segments
//				vector<string> CSVSt_poi_part;
//
//				// checking the line for the required break point
//				if (CSVSt_line.find(';') != string::npos)
//				{
//					checkbreak = ';';
//					cout << " semi-column found" << endl;
//					// declaring a string
//					string CSVSt_element;
//					// reading the stream
//					while (getline(CSVSt_stream, CSVSt_element, checkbreak))
//					{
//						CSVSt_poi_part.push_back(CSVSt_element);
//					}
//					vector<string>::iterator i;
//					i = CSVSt_poi_part.begin();
//					//moving to the next line
//					count_line2++;
//					// checking the size of the vector in order to differentiate either WP or POI
//					if (CSVSt_poi_part.size() == 5)
//					{
//						vector<string>::iterator i;
//
//						i = CSVSt_poi_part.begin();
//						// converting the stream into the double
//
//						istringstream stTost(*(i + 3));
//						istringstream stTostt(*(i + 4));
//						double poi;
//						char cc;
//						//  checking the converted streams
//						if ((stTost >> poi) && (stTostt >> poi))
//						{
//							// checking and printing the types
//							t_poi type;
//							if ((*i) == "RESTURANT")
//								type = RESTURANT;
//
//							else if ((*i) == "UNIVERSITY")
//								type = UNIVERSITY;
//
//							else if ((*i) == "NONE")
//								type = NONE;
//							// adding the poi into the database
//							poiDb.addPoi(
//									CPOI(type, *(i + 1), *(i + 2),
//											atof((*(i + 3)).c_str()),
//											atof((*(i + 4)).c_str())));
//						}
//						else
//						{
//							if ((stTost >> cc) && (stTostt >> cc))
//								cout << "attributes not be in doubled format"
//										<< endl;
//						}
//					}
//
//				}
//				else
//				{
//					cout << "the string format is not correct" << endl;
//					return false;
//				}
//			}
//		}
//		else
//		{
//			cout << "Error: File is not opened" << endl;
//			return false;
//		}
//	}
//
//	//if the mode is merging mode
//
//	else if (mode == MERGE)
//	{
//
//		ifstream filem_wp;
//		ifstream filem_poi;
//		int count_line1 = 0;
//		int count_line2 = 0;
//
//		filem_wp.open((myfilename + "-wp.txt").c_str());
//		if (filem_wp.is_open())
//		{
//			string CSVSt_line;
//			//reading the file with the help of string line
//			while (getline(filem_wp, CSVSt_line))
//			{
//				//initializing breaking word
//				char checkBreak = ' ';
//				//converting string to stream
//				istringstream CSVSt_stream(CSVSt_line);
//
//				//declaring a temporary vector
//				vector<string> CSVSt_wp_part;
//
//				if (CSVSt_line.find(';') != string::npos)
//				{
//					checkBreak = ';';
//					cout << " semi-colun found" << endl;
//					// declaring a string element
//					string CSVSt_element;
//					// checking the stream untill the required break point
//					while (getline(CSVSt_stream, CSVSt_element, checkBreak))
//					{
//						CSVSt_wp_part.push_back(CSVSt_element);
//
//					}
//					vector<string>::iterator i;
//					i = CSVSt_wp_part.begin();
//					count_line1++;
//
//					if (CSVSt_wp_part.size() == 3)
//					{
//						cout << "This segment is a Waypoint" << endl;
//						vector<string>::iterator i;
//						i = CSVSt_wp_part.begin();
//
//						istringstream stTost(*(i + 1));
//						istringstream stTostt(*(i + 2));
//						double wp;
//						char c;
//						if ((stTost >> wp) && (stTostt >> wp))
//						{
//							waypointDb.addWaypoint(
//									cWaypoint((*i), atof((*(i + 1)).c_str()),
//											atof((*(i + 2)).c_str())));
//						}
//						else if ((stTost >> c) && (stTostt >> c))
//						{
//							cout
//									<< "Error: Coordinates are not in double format"
//									<< endl;
//						}
//					}
//
//				}
//				else
//				{
//					cout << "Error: format of file is not correct, not found ;"
//							<< endl;
//				}
//			}
//		}
//		else
//		{
//			cout << "Error: file is not opened" << endl;
//			return false;
//		}
//
//		cout << "This segment is a POI" << endl;
//		filem_poi.open((myfilename + "-poi.txt").c_str());
//		if (filem_poi.is_open())
//		{
//			//string ccsv_line;
//			string CSVSt_line;
//			while (getline(filem_poi, CSVSt_line))
//			{
//				//initializing breaking word
//				char checkbreak = ' ';
//				//converting string to stream
//				//istringstream ccsv_stream(ccsv_line);
//				istringstream CSVSt_stream(CSVSt_line);
//
//				//declaring a temporary vector
//				vector<string> CSVSt_poi_part;
//
//				//checking if the line. if it have ; and its not empty
//				//if (ccsv_line.find(';') != string::npos)
//				if (CSVSt_line.find(';') != string::npos)
//				{
//					checkbreak = ';';
//					cout << " semi-colun found" << endl;
//					//string ccsv_element;
//					string CSVSt_element;
//					while (getline(CSVSt_stream, CSVSt_element, checkbreak))
//					{
//						CSVSt_poi_part.push_back(CSVSt_element);
//					}
//					vector<string>::iterator i;
//					i = CSVSt_poi_part.begin();
//					count_line2++;
//					if (!(*i).empty())
//					{
//						if (CSVSt_poi_part.size() == 5)
//						{
//							vector<string>::iterator i;
//
//							i = CSVSt_poi_part.begin();
//
//							istringstream stTost(*(i + 3));
//							istringstream stTostt(*(i + 4));
//							double dd;
//							char cc;
//
//							if ((stTost >> dd) && (stTostt >> dd))
//							{
//
//								t_poi type;
//								if ((*i) == "RESTURANT")
//									type = RESTURANT;
//
//								else if ((*i) == "UNIVERSITY")
//									type = UNIVERSITY;
//
//								else if ((*i) == "NONE")
//									type = NONE;
//
//								poiDb.addPoi(
//										CPOI(type, *(i + 1), *(i + 2),
//												atof((*(i + 3)).c_str()),
//												atof((*(i + 4)).c_str())));
//							}
//							else
//							{
//								if ((stTost >> cc) && (stTostt >> cc))
//									cout
//											<< "Error: The coordinates are not in double format"
//											<< endl;
//							}
//						}
//					}
//					else
//					{
//						cout
//								<< "Error: first element of string is empty. or iterator is not working"
//								<< endl;
//					}
//				}
//				else
//				{
//					cout << "Not able to detect"<< endl;
//					return false;
//				}
//			}
//		}
//		else
//		{
//			cout << "File cannot be opened" << endl;
//			return false;
//		}
//	}
//	return true;
//
//}
//
