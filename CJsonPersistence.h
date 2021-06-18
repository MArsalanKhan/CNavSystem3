

#ifndef CJSONPERSISTENCE_H
#define CJSONPERSISTENCE_H
#include "CPersistentStorage.h"
#include"CWpDatabase.h"
#include"CPoiDatabase.h"
#include"CWaypoint.h"
#include"CPOI.h"
#include"list"
#include <string>
#include<fstream>
#include <stdlib.h>
#include"CJsonScanner.h"
#include"CJsonToken.h"
#include"CPersistentClass.h"
#include<vector>
#include"map"


//http://stackoverflow.com/questions/15893040/how-to-create-read-write-json-files-in-qt5
//http://www.tutorialspoint.com/json/json_quick_guide.htm
//http://www.thomaswhitton.com/blog/2013/06/28/json-c-plus-plus-examples/
//https://code.google.com/p/jzon/wiki/ReadingFiles
//http://stackoverflow.com/questions/28442169/parsing-comma-separated-grammars-when-unordered
//http://www.sparxsystems.com.au/resources/uml2_tutorial/uml2_statediagram.html
//https://www.youtube.com/watch?v=_6TFVzBW7oo&index=8&list=PLGLfVvz_LVvQ5G-LdJ8RLqe-ndo7QITYc
//https://www.quora.com/What-is-the-function-of-yylex-yyin-yyout-and-fclose-yyout-in-LEX
//http://stackoverflow.com/questions/20645396/how-to-safely-read-a-line-from-an-stdistream

class CJsonPersistence : public CPersistentStorage {

	private:
	string MyfileName;

	public:
	void Extract(string &type, string &value);
	string ExtractName(string &s1);
	string GetTypeName( APT::CJsonToken::TokenType &type);
	CJsonPersistence();
	void setMediaName(string name);
	bool writeData(const CWpDatabase & waypointDb,const CPoiDatabase & poiDb);

	bool readData ( CWpDatabase & waypointDb, CPoiDatabase & poiDb,MergeMode mode);
    //bool writeData(const CWpDatabase & waypointDb);
};
/********************
**  CLASS END
*********************/
#endif /* CJSONPERSISTENCE_H */
