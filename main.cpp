// GIT-Labor   Author: Arsalan
// main.h
#include <iostream>
#include <stdlib.h>
#include "cWaypoint.h"
#include "CPOI.h"
#include "CRoute.h"
#include "CGPSSensor.h"
#include "CPoiDatabase.h"
#include "CNavigationSystem.h"
#include "CSVStorageComponent.h"
#include "CJSonPersistance.h"


int main ()
{
	/*cout<<"Project(Navigation System) is being started"<<endl;
	cout<<"=========================================="<<endl;
	cout<<"Firstly creating a test object to implement the constructor(setting parameter values)"<<endl;
	cWaypoint Testobject("Test object",56.78,77.32);


	cout<<"=========================================="<<endl;
	cout<<"Now Creating four objects(namely: Amsterdam ,Berlin ,Darmstadt ,Tokio) with their paameters"<<endl;
	cWaypoint Amsterdam("Amsterdam",52.367,4.9000);
	cout<<endl;
	cWaypoint Berlin("Berlin",52.516,13.4);
	cout<<endl;
	cWaypoint Darmstadt("Darmstadt",49.867,8.650);
	cout<<endl;
    cWaypoint Tokio("Tokio",35.683,139.683);
    cout<<endl;
    cWaypoint Karachi("Karachi",24.893379,67.0280609);
   cout<<"Now Creating anothe Object namely newWaypoint without the parameter list(default values of constructor)"<<endl;
	cWaypoint newWayPoint;
	cout<<"Printing latitude and longitude of Berlin in both Decimal and degmmss format"<<endl<<endl;
	int format;
	cout<<"Print Method"<<endl;
	cout<<"=========================================="<<endl;
	cout<<"Press 1:(Latitude and Longitude in Decimal) or Press 2(Latitude and Longitude in Degmmss format)"<<endl;
	cin>>format;
	Berlin.print(format);
	cout<<"Latitude and longitude of Berlin in Decimal format is"<<endl;
    Berlin.print(1);
    cout<<"Latitude and longitude of Berlin in degmmss format is"<<endl;
    Berlin.print(2);
    cout<<"=========================================="<<endl;
    cout<<"Providing a test Case for the functions getName,getLatitude,getLongitude"<<endl;
    Berlin.getName();
    Berlin.getLatitude();
    Berlin.getLongitude();
    cout<<"=========================================="<<endl;
    cout<<"Defining local variables"<<endl;
    string name;
    double longitude;
    double latitude;
    cout<<"Getting all data by reference of Tokio in a single call"<<endl;
    Tokio.getAllDataByReference(name,latitude,longitude);
    cout<<"The name is"<<name<<" " <<"with address"<<&name<<endl;
    cout<<"The latitude is"<<latitude<<"with address"<<&latitude<<endl;
    cout<<"The longitude is"<<longitude<<"with address"<<&longitude<<endl;
    cout<<"and a fist real method"<<endl;
    cout<<"=========================================="<<endl;
    Amsterdam.calculateDistance(Berlin);//Calculating distance
    Tokio.calculateDistance(Berlin);  //Calculating distance*/

     //Now running the progam through Class CNavigationSystem(Core System)
	CNavigationSystem Navigating;
	Navigating.run();


 //Templatedclass<string,CPOI> obj;
 //obj.printDB();
//	cWpDatabase m_wpdatabase;
//	m_wpdatabase.printWp();
	//cWaypoint Amsterdam("Amsterdam",52.3667,4.9000);
	//cWaypoint Darmstadt("Darmstadt",49.8667,8.6500);
//    cWaypoint Berlin("Berlin",52.5167,13.3833);
//m_wpdatabase.addWaypoint(Amsterdam);
	//m_wpdatabase.addWaypoint(Darmstadt);
//    m_wpdatabase.addWaypoint(Berlin);
	//CPoiDatabase m_PoiDatabase;
	//CPOI HdaMensa(RESTURANT,"Mensa HDA","The Best Mensa in the World",10,20);
	//m_PoiDatabase.addPoi(HdaMensa);
//
//
//
//		CSVStorageComponent obj;
////		obj.setMediaName("Waypoints");
//		obj.setMediaName("tahir");
//		obj.writeData(m_wpdatabase,m_PoiDatabase);

//		CNavigationSystem obj2;
//		obj2.connectPersistance("Dada",m_wpdatabase,m_PoiDatabase);

//	CNavigationSystem obj;

			//CJSonPersistance obj;
			//obj.setMediaName("Waypoints");
			//obj.setMediaName("tahir");
			//obj.writeData(m_wpdatabase,m_PoiDatabase);

    return 0;
}
