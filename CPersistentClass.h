/*
 * CPersistentClass.h
 *
 *  Created on: Dec 7, 2015
 *      Author: abd sharaf
 */

#ifndef CPERSISTENTCLASS_H_
#define CPERSISTENTCLASS_H_
#include "CPersistentStorage.h"

#include<fstream>
#include <string>
#include <iostream>
#include"CWpDatabase.h"
#include"CPoiDatabase.h"
#include"CWaypoint.h"
#include"CPOI.h"
#include"list"

class CPersistentClass: public CPersistentStorage
{
private:
	string MyfileName;

public:
	CPersistentClass();
	virtual ~CPersistentClass();
	void setMediaName(string name);
	bool writeData(const CWpDatabase & waypointDb,const CPoiDatabase & poiDb);

	bool readData ( CWpDatabase & waypointDb, CPoiDatabase & poiDb,MergeMode mode);
	string getName(string,int);
	double getNumber(string,int);
	bool is_double(const string& s);

	t_poi getType(string& Type) const;

};

#endif /* CPERSISTENTCLASS_H_ */
