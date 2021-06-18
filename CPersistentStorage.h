/*
 * CPersistentStorage.h
 *
 *  Created on: Dec 5, 2015
 *      Author: Arsalan
 */

#ifndef CPERSISTENTSTORAGE_H_
#define CPERSISTENTSTORAGE_H_
#include <string>
#include <iostream>
#include"CWpDatabase.h"
#include"CPoiDatabase.h"
class CPersistentStorage
{
public:
	virtual ~CPersistentStorage(){};
	virtual void setMediaName(string name)=0;
	virtual bool writeData(const CWpDatabase & waypointDb,
			const CPoiDatabase & poiDb)=0;
	enum MergeMode
	{
		MERGE, REPLACE
	};
	virtual bool readData(CWpDatabase & waypointDb, CPoiDatabase & poiDb,
			MergeMode mode)=0;
};

#endif /* CPERSISTENTSTORAGE_H_ */
