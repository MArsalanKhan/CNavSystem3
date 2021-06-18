/*
 * CRoute.h
 *
 *  Created on: 02.11.2015
 *      Author: Arsalan
 */

#ifndef CROUTE_H_
#define CROUTE_H_
using namespace std;
#include <iostream>
#include <string.h>
#include "cWaypoint.h"
#include "CPOI.h"
#include "CPoiDatabase.h"
#include "cWpDatabase.h"
#include <list>
#include <vector>
class CRoute
{
private:

CPoiDatabase *m_pPoiDatabase;
cWpDatabase *m_pWpDatabase;
list <cWaypoint*> mRoute;


public:

CRoute();
CRoute(const CRoute &origin);
~CRoute();
void connectToPoiDatabase(CPoiDatabase *pPoiDB);
void connectToWpDatabase(cWpDatabase* pWpDB);
void addWaypoint(string name);
void addPoi(string namePoi,string afterWp);
double getDistanceNextPoi (const cWaypoint &wp,CPOI &poi);
int getNumberOfPOI();
void print();
CRoute & operator =(const CRoute &origin);
friend CRoute & operator +(CRoute &route1 ,CRoute &route2);
void operator +=(string name);
 vector<const cWaypoint* > getRoute() const;

};





#endif /* CROUTE_H_ */
