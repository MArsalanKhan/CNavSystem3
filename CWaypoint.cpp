/*
 * CWaypoint.cpp
 *
 *  Created on: .11.2015
 *      Author: DELL
 */
#include "cWaypoint.h"
#include <iostream>
using namespace std;
#include<math.h>



/* Implementation of the Constructor of CWaypoint & printing addresses of Object and attributes*/


cWaypoint::cWaypoint(string name,double latitude,double longitude)

{
   // setting the attributes using set function and chaecking the range of latitude and longitude
	set(name,latitude,longitude);


#ifdef SHOWADDRESS

	cout<<"The object has been created at address"<<this<<endl;
	cout<<"The name is"<<"   "<<m_name<<"   "<<"Created at an address"<<&m_name<<endl;
	cout<<"The Latitude of"<<"  "<<m_name<<"  "<<"is"<<"   "<<m_latitude<<"   "<<"Created at an address"<<&m_latitude<<endl;
	cout<<"The  Longitude of"<<"  "<<m_name<<"  "<<"is"<<"   "<<m_longitude<<"   "<<"Created at an address"<<&m_longitude<<endl;

#endif

}

// Implementing the Set method ,checking and assigning the correct values to the attributes


void cWaypoint::set(string name,double latitude,double longitude)

{
	m_name=name;
	if(latitude >=-90 && latitude<=90 )
	{
		m_latitude=latitude;
	}

	else
	{
		m_latitude=0;
	}

	if(longitude >=-180 && longitude<=180 )
		{
			m_longitude=longitude;
		}

		else
		{
			m_longitude=0;
		}


}

//printing the name,latitude and longitude by checking the format choose by the user
//Implementing Print Method which takes format 1 0r 2 as parameter and print values either in decimal or degree,minute and second format

void cWaypoint::print(int format)
{
	int deg;
	int mm;
	double ss;
	if(format==1)
	{

		//cout<<"The Latitude of "<<m_name<<m_latitude<<endl;
		//cout<<"The Longitude is"<<m_name<<m_longitude<<endl<<endl;

	}

     else if(format==2)
	{
       //converting latitude from decimal to degree min sec foramt
		transformLatitude2degmmss(deg,mm,ss);

		//converting latitude from decimal to degree min sec foramt

		transformLongitude2degmmss(deg,mm,ss);

	}

	else
	{
		cout<<"Kindly read the Manual"<<endl;
	}



}


//implementation of transformLatitude2degmmss
void cWaypoint:: transformLatitude2degmmss(int &deg,int &mm,double &ss)

{

	  deg=(int)m_latitude;
	  mm=((m_latitude)-(deg))*(60);
	  ss=(((m_latitude)-(deg))-(mm/60.0))*(3600);
	  //cout<<m_name<<"  "<<"on latitude "<<"=";
	  //cout<<deg<<"deg"<<"   "<<mm<<"min"<<"    "<<ss<<"sec";
}

// Transformation of longitude in degree,minutes,and seconds

void cWaypoint:: transformLongitude2degmmss(int &deg,int &mm,double &ss)

{

  deg=(int)m_longitude;
  mm=((m_longitude)-(deg))*(60);
  ss=(((m_longitude)-(deg))-(mm/60.0))*(3600);
  //cout<<" "<<"and longitude=";
  //cout<<deg<<"deg"<<"   "<<mm<<"min"<<"    "<<ss<<"s"<<"    "<<endl;
}


string cWaypoint::getName() const
{
	//cout<<m_name<<endl;
    return m_name;
}

double cWaypoint::getLatitude()
{
	//cout<<"The latitude of "<<m_name<<" is "<<m_latitude<<endl;
	return m_latitude ;

}


double cWaypoint::getLongitude()

{
	//cout<<"The Longitude of "<<m_name<<" is"<<"   "<<m_longitude<<endl;
	return m_longitude;
}

//getting all data by reference in a single call
void cWaypoint::getAllDataByReference(string &name,double &latitude,double &longitude) const

{
name=m_name;
latitude=m_latitude;
longitude=m_longitude;

}


//implemnting calculate distance function
double cWaypoint::calculateDistance(const cWaypoint &wp)
{
double distance;
distance= R*acos(sin(m_latitude*(PI/180))*sin(wp.m_latitude*(PI/180))+cos(m_latitude*(PI/180))*cos(wp.m_latitude*(PI/180))*cos(wp.m_longitude*(PI/180)-m_longitude*(PI/180)));
return distance ;
}

//overloaded operator to print the waypoint from print function of CRoute
ostream& operator<<(ostream & out,cWaypoint &wp)
{

	//wp.print(2);
	return out;



}
