/*
 * CNavigationSystem.h
 *
 *  Created on: 02.11.2015
 *      Author: DELL
 */

#ifndef CNAVIGATIONSYSTEM_H_
#define CNAVIGATIONSYSTEM_H_

using namespace std;
#include <iostream>
#include <string.h>
#include "CPoiDatabase.h"
#include  "CRoute.h"
#include "CGPSSensor.h"
#include "CJSonPersistance.h"
#include "cWaypoint.h"
#include "CPOI.h"


class CNavigationSystem
{
private:
	string m_name;
	cWpDatabase m_wp;
	CPoiDatabase m_Poi;
	CGPSSensor m_GPSSensor;
	CRoute m_route;
	CPoiDatabase m_PoiDatabase;
	cWpDatabase m_WpDatbase;
	void enterRoute();
	void printRoute();
	void printDistanceCurPoNextPoi();

public:

	void connectPersistance(cWpDatabase &wpDb,CPoiDatabase & poiDb);
	CNavigationSystem();
	void run();

};



#endif /* CNAVIGATIONSYSTEM_H_ */
