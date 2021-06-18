
/*
 * CPOI.cpp
 *
 *  Created on: 02.11.2015
 *      Author: Arsalan
 */
using namespace std;
#include <iostream>
#include <string.h>
#include "CPOI.h"

//constructor of CPOI
CPOI::CPOI(t_poi type,string name,string description,double latitude,double longitude): cWaypoint(name,latitude,longitude)
{
	m_type=type;
    m_description=description;


}
void CPOI::getAllDataByReference(string &name,double &latitude,double &longitude,t_poi &type,string &description)
{
	name=m_name;
	latitude=m_latitude;
	longitude=m_longitude;
	type=m_type;
	description=m_description;
}

void CPOI:: print(int format)
{


		switch(m_type)
		{
		case RESTURANT:
			cout<<"Point of interest is of type:"<<endl;
			cout<<"Resturant  "<<"and it is"<<m_description<<endl;
			cWaypoint::print(format);
			break;

		case UNIVERSITY:
			cout<<"Point of interest is of type:"<<endl;
		        cout<<"University"<<"and it is  "<<m_description<<endl;
			cWaypoint::print(format);
			break;

		case NONE:
			cout<<"Point of interest is of type:"<<endl;
		        cout<<"None"<<"and it is"<<m_description<<endl;
		        cWaypoint::print(format);
		    break;



       }




}

ostream& operator<<(ostream & out,CPOI &poi)
{

poi.print(2);

return out;

}
 // in order to get description inside CSVStorageClass
string CPOI::getDescription()

{
	return m_description;

}
// in order to get type inside CSVStorageClass

string CPOI:: getType()
{
    string type;

	switch(m_type)

	{
	case RESTURANT:

		type="Resturant";
		break;

	case UNIVERSITY:
		type="University";
		break;

	case NONE:
		type="None";
		break;

	default:
		break;

	}

	return type;

}





