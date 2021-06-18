/*
 * cWaypoint.h
 *
 *  Created on: Nov 7, 2015
 *      Author: Arsalan
 */

#ifndef CWAYPOINT_H_
#define CWAYPOINT_H_


using namespace std;
#include <iostream>
#include <string.h>
#define PI 3.14159
#define R 6378
#include <math.h>
//Declaration of the class CWaypoint.h

class cWaypoint

{
protected:
	string m_name;
	double m_latitude;
	double m_longitude;


private:
	void calculateXYZ(double &x,double &y,double &z);
	void transformLongitude2degmmss(int &deg,int &mm,double &ss);
	void transformLatitude2degmmss(int &deg,int &mm,double &ss);



public:

	cWaypoint(string name="No name",double latitude=0,double longitude=0);
	void set(string name,double latitude,double longitude);
	string getName() const ;
	double getLatitude();
	double getLongitude();
	void getAllDataByReference(string &name,double &latittude,double &longitude) const;
	double calculateDistancePlain(const cWaypoint &wp);
	double calculateDistance(const cWaypoint &wp);
	virtual void print(int format);
	friend ostream& operator<<(ostream &out ,cWaypoint &wp);

};

#endif /* CWAYPOINT_H_ */
