/*
 * CGPSSensor.h
 *
 *  Created on: 05.11.2015
 *      Author: Arsalan
 */

#ifndef CGPSSENSOR_H_
#define CGPSSENSOR_H_

using namespace std;
#include <iostream>
#include <string.h>
#include "cWaypoint.h"

class CGPSSensor
{
public:
	CGPSSensor();
	cWaypoint getCurrentPosition();

private:


};




#endif /* CGPSSENSOR_H_ */
