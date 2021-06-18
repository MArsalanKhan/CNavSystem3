/*
 * CRoute.cpp
 *
 *  Created on: 02.11.2015
 *      Author: DELL
 */

#include <iostream>
using namespace std;
#include<string.h>
#include "CRoute.h"
#include"cWaypoint.h"
#include"CPOI.h"
#include"CPoiDatabase.h"
#include "cWpDatabase.h"


CRoute::CRoute()

{

m_pPoiDatabase=0;
m_pWpDatabase=0;


}


CRoute::~CRoute()
{

}

CRoute::CRoute(const CRoute &origin)
{

	  mRoute = origin.mRoute;
	  m_pWpDatabase= origin.m_pWpDatabase;
	  m_pPoiDatabase= origin.m_pPoiDatabase;

}


//connecting our route with database of POI
void CRoute::connectToPoiDatabase(CPoiDatabase *pPoiDB=NULL)
{
	m_pPoiDatabase=pPoiDB;
}

//connecting our route with database of Waypoints
void CRoute::connectToWpDatabase(cWpDatabase *pWpDB=NULL)

{
	m_pWpDatabase =pWpDB;
}

//adding our waypoints from Database to Route
void CRoute:: addWaypoint(string name)
{
if(m_pWpDatabase!=NULL)
{
    if(m_pWpDatabase->getPointerToWaypoint(name)!=NULL)
    {
    	cWaypoint *wp = m_pWpDatabase->getPointerToWaypoint(name) ;
    	mRoute.push_back(wp);
    	//cout<<"Way point added into the route"<<endl;
    	//cout<<wp->getName()<<endl;
     }

}

else
{
	cout<<"Database not connected to route"<<endl;
}
//    else
//
////    {
////    	cout<<"No Way point found"<<endl;
////
////    }


}

//adding our Pois from Database to route
void CRoute::addPoi(string namePoi,string afterWp)

{
	if(m_pPoiDatabase!=NULL && m_pWpDatabase!=NULL)

{
	if((m_pPoiDatabase->getPointerToPoi(namePoi)!=NULL) && (m_pWpDatabase->getPointerToWaypoint(afterWp)!=NULL))
	{

		list<cWaypoint*>:: iterator it;
		for(it=mRoute.begin();it!=mRoute.end();)
		{
			if((*it)->getName()==afterWp)
			{
  // inserting Poi after searching corresponding waypoint by using pre-increment operator
			//cout<<"POI is also added into the Route"<<endl;

		    mRoute.insert(++it,m_pPoiDatabase->getPointerToPoi(namePoi));
		    //cout<<namePoi<<endl;

		   // cout<<"With the name"<<(*it)->getName()<<endl;


			}

			else
			{
				it++;
				//cout<<"afterWay point not found"<<endl;
			}
		}

	}

	else
	{
		cout<<"Database is not connected"<<endl;
	}

	 }

	else
	{
		cout<<"No match found"<<endl;
	}

}

void CRoute:: print()
{

	list<cWaypoint*>:: iterator it;

	for(it=mRoute.begin();it!=mRoute.end();++it)
	{

       // (*it)->print(2);
		//cout<<(**i)<<endl; //Naive approach is giving error Invalid Overloading of endl operator.

		CPOI *tempPoi =dynamic_cast <CPOI*> (*it);
		if(tempPoi==NULL)
		{
			(*it)->print(2);


		}

		else
		{

			tempPoi->print(2);
		}
	}

}


CRoute & CRoute:: operator =(const CRoute &origin)
{
	 mRoute = origin.mRoute;
     m_pWpDatabase= origin.m_pWpDatabase;
     m_pPoiDatabase= origin.m_pPoiDatabase;
     return *this;
}

void CRoute::operator +=(string name)
{

	CRoute::addWaypoint(name);
	CRoute::addPoi(name,name);


//	cWaypoint *tempWp =  m_pWpDatabase->getPointerToWaypoint(name);
//	CPOI *tempPoi= m_pPoiDatabase->getPointerToPoi(name);
//
//		if(tempWp!=NULL)
//		{
//			mRoute.push_back(tempWp);
//
//		     if(tempPoi!=NULL)
//		     {
//		    	 mRoute.push_back(tempPoi);
//
//		     }
//
//		     else
//		     {
//		    	 cout<<"POI not found"<<endl;
//		     }
//
//
//		  }
//		 else
//				 {
//					 cout<<"No Waypoint found"<<endl;
//				 }

}

vector<const cWaypoint* > CRoute::getRoute() const
{

	vector<const cWaypoint*> myRoute;
     list<cWaypoint*>::const_iterator it;
	for(it=mRoute.begin();it!=mRoute.end();++it)
	{
		myRoute.push_back(*it);
	}

	return myRoute;

}



