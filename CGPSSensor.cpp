/*
 * CGPSSensor.cpp
 *
 *  Created on: 05.11.2015
 *      Author: Arsalan
 */

using namespace std;
#include <iostream>
#include <string.h>
#include "CGPSSensor.h"
#include "cWaypoint.h"


CGPSSensor::CGPSSensor()
{

}
cWaypoint CGPSSensor::getCurrentPosition()
{
  //Creating local variables
string name;
double latitude,longitude;
cout<<"GPS Sensor"<<endl;
cout<<"Enter Latitude:\n ";
//Taking current position from User
cin>>latitude;
cout<<"Enter the longitude:\n ";
cin>>longitude;
cout<<"Your entered Positions are "<<endl<<"Latitude:"<<latitude<<endl<<"Longitude: "<<longitude;
//Returning the current position
cWaypoint CurrentPosition("current position",latitude,longitude);
return CurrentPosition;
}



