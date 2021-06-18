/*
 * CpoiDatabase.cpp
 *
 *  Created on: 02.11.2015
 *      Author: DELL
 */
#include <iostream>
#include <string.h>
#include "CPoiDatabase.h"
#include "CPOI.h"
#include "cWaypoint.h"
//#include "CRoute.h"
#include <string>
#include <map>
using namespace std;

CPoiDatabase::CPoiDatabase()
{


}

//adding POI to our database
void CPoiDatabase::addPoi(CPOI const & poi)
{

// // invoking the templated function
	addinDataBase( poi);


//       string name;
//        name=poi.getName();
//	    Poi.insert(pair<string,CPOI>(name,poi));
//
//	    //In order to check whether POIs are added in our route or not,we are making a loop
//
//	    map<string,CPOI> :: iterator i;
//
//	    for(i=Poi.begin();i!=Poi.end();i++)
//	    {
//
//	    	cout<<"CPOI added into the POI Database with Name"<<"     "<<i->first<<endl;
//
//	    }

}



CPOI* CPoiDatabase::getPointerToPoi(string name)

{
//// invoking the templated function
	return getPointerToDataBase(name);


//    map <string,CPOI> :: iterator it;
//    //Making a a loop in order to check the required Poi
//	for(it=Poi.begin(); it!=Poi.end(); ++it)
//	{
//            if(name == (*it).first)
//            {
//               // returning the address of required Poi to be added into the Route List
//            	return &((*it).second);
//
//            }
//
//            else
//            {
//            	//cout<<"Requird Way point is not in Poi Database"<<endl;
//            }
//
//
//	}

  return 0;


}

//in order to get copy of container inside CSVStorageComponent
void CPoiDatabase::GetmapPoi()
{


	getMapDataBaseWpPoi();


//	map<string,CPOI>:: iterator it=Poi.begin();
//
//	for(;it!=Poi.end();++it)
//	{
//
//		 mapPoi.insert(pair<string,CPOI>(it->first,it->second)) ;
//
//
//	}

}

//for replace case inside read function of CSVStorageComponent
void CPoiDatabase::clearDB()
{
	clear_T_DB();
}

void CPoiDatabase::printPoi()
{

	printDB();
}
