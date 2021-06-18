/*
 * CaddWp.h
 *
 *  Created on: Jan 20, 2016
 *      Author: Arsalan Khan
 */

#ifndef CADDWP_H_
#define CADDWP_H_

#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>

#include "../myCode/CRoute.h"
using namespace std;


// Testing of the function addWaypoint in CRoute class



class CaddWp: public CppUnit::TestFixture
{
private:
	CRoute* m_route;
	//CPoiDatabase m_PoiDatabase;
	CWpDatabase m_pWpDatabase;

public:
// Creating waypoints
	void setUp()
		{
			m_route = new CRoute;



			CWaypoint WP_Amsterdam("Amsterdam",52.3731,4.8922);
			CWaypoint WP_Darmstadt("Darmstadt", 49.850, 8.6527);

			 m_pWpDatabase.addWaypoint(WP_Amsterdam);
		     m_pWpDatabase.addWaypoint(WP_Darmstadt);




		}


	void tearDown()
		{
			delete m_route;
		}

// Connecting The route to Waypoint Database
	void WpDatabaseconnect()
		{

		    m_route->connectToWpDatabase(&m_pWpDatabase);
			m_route->addWaypoint("Amsterdam");
			CPPUNIT_ASSERT(1==m_route->getRoute().size());

			m_route->connectToWpDatabase(&m_pWpDatabase);
			m_route->addWaypoint("Amsterdam");
			CPPUNIT_ASSERT(2==m_route->getRoute().size());

		}

// Performing the test operation to check whether the waypoints are added into the route or not.

	void testaddWp()
		{
			m_route->addWaypoint("Amsterdam");
			m_route->addWaypoint("Darmstadt");

			CPPUNIT_ASSERT(0==m_route->getRoute().size());


			m_route->connectToWpDatabase(&m_pWpDatabase);

			m_route->addWaypoint("Sttutgart");
			CPPUNIT_ASSERT(0==m_route->getRoute().size());

			m_route->addWaypoint("Amsterdam");
			m_route->addWaypoint("Darmstadt");

			CPPUNIT_ASSERT(2==m_route->getRoute().size());


		}

	static CppUnit::TestSuite* suite()
		{
			CppUnit::TestSuite* suite = new CppUnit::TestSuite("Selection Tests");
			suite->addTest(new CppUnit::TestCaller<CaddWp>("Waypoint Database Connection Testing",
					&CaddWp::WpDatabaseconnect));

			suite->addTest(new CppUnit::TestCaller<CaddWp>("Adding Waypoints in Database Testing",
					&CaddWp::testaddWp));






			return suite;

		}


};

#endif /* CADDWP_H_ */
