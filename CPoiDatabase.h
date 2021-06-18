/*
 * CPoiDatabase.h
 *
 *  Created on: 02.11.2015
 *      Author: Arsalan
 */

#ifndef CPOIDATABASE_H_
#define CPOIDATABASE_H_


#include <iostream>
#include <string.h>
#include"CPOI.h"
#include <map>
#include "Templatedclass.h"

class CPoiDatabase : public Templatedclass <string,CPOI>


{
private:

map<string,CPOI> Poi;

public:
	//void GetmapPoi(map<string,CPOI> & )  ;
void GetmapPoi( );
	CPoiDatabase();
	void addPoi(CPOI const & poi);
	CPOI *getPointerToPoi(string name);
	void clearDB();
	void printPoi();
};


#endif /* CPOIDATABASE_H_ */
