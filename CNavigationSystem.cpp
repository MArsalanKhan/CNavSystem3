
/*
 * CNavigationSystem.cpp
 *
 *  Created on: 02.11.2015
 *      Author: Arsalan
 */
using namespace std;
#include <iostream>
#include <string.h>
#include "CPoiDatabase.h"
#include "CRoute.h"
#include "CGPSSensor.h"
#include "CNavigationSystem.h"
#include "cWpDatabase.h"
//#include "CSVStorageComponent.h"



CNavigationSystem::CNavigationSystem()
{


}

void CNavigationSystem::enterRoute()
{
    //creating Waypoints for our route
	cWaypoint Amsterdam("Amsterdam",52.3667,4.9000);
    cWaypoint Darmstadt("Darmstadt",49.8667,8.6500);
   // cWaypoint Berlin("Berlin",52.5167,13.3833);
    //cWaypoint Tokio("Tokio",35.6833,139.6833);

    //adding waypoints in our waypoint database
    m_WpDatbase.addWaypoint(Amsterdam);
    m_WpDatbase.addWaypoint(Darmstadt);
  // m_WpDatbase.addWaypoint(Berlin);
   // m_WpDatbase.addWaypoint(Tokio);

//connecting waypoint to route
  m_route.connectToWpDatabase(&m_WpDatbase);


    //Adding Waypoints in our route

    m_route.addWaypoint("Amsterdam");
    m_route.addWaypoint("Darmstadt");
    m_route.addWaypoint("Berlin");
   // m_route.addWaypoint("Tokio");

    //creating CPOIs
   CPOI HdaMensa(RESTURANT,"Mensa HDA","The Best Mensa in the World",10,20);
   CPOI Sitte(RESTURANT,"Sitte","More Expensive but also good",11,22);
   CPOI HDAUni(UNIVERSITY,"HDA","My Best University",10.21,20.23);
   //CPOI TUDarmstad(UNIVERSITY,"TU Darmstadat","also a good univeristy",49.86954,8.6800583);
    CPOI KFC(RESTURANT,"KFC","Best in Amsterdam",52.31,4.89);
    CPOI Ber_Uni(UNIVERSITY,"Ber_Uni","Best Uni in Berlin",52.51,13.299);




  //  adding POIs in our database

   m_PoiDatabase.addPoi(HdaMensa);
   //m_PoiDatabase.addPoi(Sitte);
    m_PoiDatabase.addPoi(HDAUni);
   // m_PoiDatabase.addPoi(TUDarmstad);
    m_PoiDatabase.addPoi(KFC);
    //m_PoiDatabase.addPoi(Ber_Uni);
    //m_PoiDatabase.addPoi(HdaMensa);
    //m_PoiDatabase.addPoi(HdaMensa);


    //Connecting route with Database

  m_route.connectToPoiDatabase(&m_PoiDatabase);

    //adding POIs to the routes
    m_route.addPoi("Mensa HDA","Darmstadt");
   // m_route.addPoi("Sitte","Darmstadt");
    m_route.addPoi("HDA","Darmstadt");
    m_route.addPoi("KFC","Amsterdam");
    //m_route.addPoi("Ber_Uni","Berlin");


}

//printing the route which has been created
void CNavigationSystem:: printRoute()
{
	m_route.print();
}

// runnig the navigation system
void CNavigationSystem:: run()
{
	enterRoute();
	//system("pause");
	printRoute();
	connectPersistance(m_WpDatbase,m_PoiDatabase);




}

void CNavigationSystem:: connectPersistance(cWpDatabase &wpDb,CPoiDatabase & poiDb)

{
	CJSonPersistance temp;
	//m_name=name;
	m_wp=wpDb;
	m_Poi=poiDb;

	temp.setMediaName("My-Text file # 1");
	temp.writeData(m_wp,m_Poi);
	//temp.readData(m_wp,m_Poi,REPLACE);
	//temp.setMediaName("My-Text file # 2");
	//temp.writeData(m_wp,m_Poi);



}

