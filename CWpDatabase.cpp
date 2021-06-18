/*
 * cWpDatabase.cpp
 *
 *  Created on: 27.11.2015
 *      Author: DELL
 */

#include "cWpDatabase.h"
#include "cWaypoint.h"
#include <iostream>



cWpDatabase::cWpDatabase()
{

}

void cWpDatabase::addWaypoint(cWaypoint const &wp)

{

  // simply invoking the templated function for adding in the database
     addinDataBase( wp);




	//cWpDatabase obj;
	//obj.addinDataBase(T const &obj);

//	string name;
//	name= wp.getName() ;
//	m_wp.insert(pair<string,cWaypoint>(name,wp));
//
//	//In order to check whether WayPoint is added in our route or not,we are making a loop
//
//	map<string,cWaypoint> :: iterator i;
//for(i=m_wp.begin();i!=m_wp.end();++i)
//	{
//       cout<<"Way point added into the Way point Data base with the name"<<i->first<<"   "<<endl;
//
//	}



}

// the function to pass the container for persistance storage
void cWpDatabase::GetmapWp()

{
  // invoking the templated function
	getMapDataBaseWpPoi();


//	map<string,cWaypoint>:: const_iterator i;
//	for(i=m_wp.begin();i!=m_wp.end();i++)
//	{
//		mapWp.insert(pair<string,cWaypoint>(i->first,i->second));
//	}


}

cWaypoint* cWpDatabase:: getPointerToWaypoint(string name)
{
  // invoking the templated function
	return getPointerToDataBase(name);


//	map <string,cWaypoint> :: iterator it;
//		for(it=m_wp.begin(); it!=m_wp.end(); ++it)
//		{
//	            if(name == (*it).first)
//	            {
//
//	            	return &((*it).second);
//
//	            }

//	            else
//	            {
//	            	cout<<"The required waypoint is not found in Waypoint Database"<<endl;
//	            }

		//}



}
// for the replace purpose, clearing the database
void cWpDatabase::clearDB()
{
 clear_T_DB();
}
void cWpDatabase:: printWp()
{
     printDB();
}
