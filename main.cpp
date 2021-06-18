

#include <cppunit/TestCase.h>
#include <cppunit/TestSuite.h>
#include <cppunit/ui/text/TestRunner.h>
#include"CaddWp.h"
#include"CaddPoi.h"
#include"COperator.h"

using namespace CppUnit;

int main (int argc, char* argv[]) {

	TextUi::TestRunner runner;
	// runner.addTest( new CLoadExisting() );
//	runner.addTest( CLoadTests::suite() );
	runner.addTest( CaddWp::suite() );
	runner.addTest( CaddPoi::suite() );
	runner.addTest( COperator::suite() );
	runner.run();

	return 0;
}





