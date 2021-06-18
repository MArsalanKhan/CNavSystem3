/*
 * cWpDatabase.h
 *
 *  Created on: 27.11.2015
 *      Author: DELL
 */

#ifndef CWPDATABASE_H_
#define CWPDATABASE_H_
#include "cWaypoint.h"
#include "Templatedclass.h"
#include "cWpDatabase.h"
#include <map>
#include <iostream>

class cWpDatabase : public Templatedclass <string,cWaypoint>

{

private:
//
	 map<string,cWaypoint> m_wp;
public:
	//void GetmapWp(map<string,cWaypoint> &mapwp) const;
	 void GetmapWp( );
     cWpDatabase();
	void addWaypoint(cWaypoint const &wp);
	cWaypoint* getPointerToWaypoint(string name);
	//void print();
	void clearDB();
	void printWp();


};

#endif /* CWPDATABASE_H_ */
