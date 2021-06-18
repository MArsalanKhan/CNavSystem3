/*
 * CJSonPersistance.h
 *
 *  Created on: 07.01.2016
 *      Author: Arsalan
 */

#ifndef CJSONPERSISTANCE_H_
#define CJSONPERSISTANCE_H_
#include "CPersistanceStorage.h"
#include <fstream>
#include <ostream>
#include <iostream>
#include <string>
#include <string.h>
#include "CPoiDatabase.h"
#include "CRoute.h"
#include "CGPSSensor.h"
#include "CNavigationSystem.h"
#include "cWaypoint.h"
#include "CPOI.h"
#include "cWpDatabase.h"
#include <string>
#include <map>
#include <cstdlib>
#include <sstream>
#include <vector>
#include "CJsonScanner.h"
#include "CJsonToken.h"
using namespace std;
enum States {
		Waiting_for_first_token_OR_idle_state,
		Waiting_for_db_name,
		Waiting_for_db_begin,
		Waiting_for_attribute_name,
		Waiting_for_attribute_value,
		Waiting_for_DB_name_separator,
		Waiting_for_object_name_separator,
		Waiting_for_value_separator,
		Waiting_for_next_object,
		Waiting_for_db_end,
		Waiting_for_object
     };

class CJSonPersistance : public CPersistanceStorage
{
private:
	string myfilename;
	bool printCommon(string name,double latitude,double longitude,ofstream &cwp );
public:
//	CJSonPersistance();
//	virtual ~CJSonPersistance();
	bool writeData (const cWpDatabase& waypointDb,const CPoiDatabase& poiDb);
	bool readData (cWpDatabase& waypointDb, CPoiDatabase& poiDb,MergeMode mode);
    void setMediaName(string name);






};

#endif /* CJSONPERSISTANCE_H_ */
