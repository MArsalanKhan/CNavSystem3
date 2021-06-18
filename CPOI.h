/*
 * CPOI.h
 *
 *  Created on: 06.11.2015
 *      Author: DELL
 */

#ifndef CPOI_H_
#define CPOI_H_

using namespace std;
#include <iostream>
#include <string.h>
#include "cWaypoint.h"
enum t_poi{RESTURANT,UNIVERSITY,NONE};


class CPOI : public cWaypoint

{
private:
	string m_description;
     t_poi m_type;
public:
	virtual void print(int format);
	CPOI(t_poi type=RESTURANT,string name ="no name",string description="no description",double latitude=0,double longitude=0);
	void getAllDataByReference(string &name,double &latitude,double &longitude,t_poi &type,string &description);
	friend ostream& operator<<(ostream &out ,CPOI &wp);
	string getDescription();
	string getType();


};



#endif /* CPOI_H_ */
