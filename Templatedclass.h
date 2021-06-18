/*
 * Templatedclass.h
 *
 *  Created on: 01.01.2016
 *      Author: Arsalan
 */

#ifndef TEMPLATEDCLASS_H_
#define TEMPLATEDCLASS_H_
#include <map>
#include <string>
#include <iostream>
using namespace std;
#include "cWaypoint.h"
#include "CPOI.h"
//#include "cWpDatabase.h"
//declaring a templated class for wp and poi databases
template <class key,class T>
class Templatedclass
{
private:
	map<key,T> DatbaseWpPoi;
public:
	void addinDataBase(T const &obj);
	T* getPointerToDataBase(string name);
	map<key,T> getMapDataBaseWpPoi();
	void clear_T_DB();
	Templatedclass()
	{

	}
	virtual ~Templatedclass()
	{

	}

	void printDB();

};

// implementing the generic function to addd WP or POI inside the DB
template <class key,class T>
void Templatedclass<key,T>::addinDataBase(T const &obj)
{
	//string name;
	cout<<"\n object added in data base with the name"<<obj.getName()<<endl;

	DatbaseWpPoi.insert(pair<key,T>(obj.getName(),obj));
//	int counter;
//	cout<<"objects in map are"<<++counter<<endl;


}

// implementing the generic function to get pointers from WP and Poi databases and putting them inside the route
template <class key,class T>
T* Templatedclass<key,T>::getPointerToDataBase(string name)

{

	typename map <string,T>:: iterator it ;
	for(it=DatbaseWpPoi.begin(); it!=DatbaseWpPoi.end();it++)
	{

           if(name==it->first)
           {

        	   return &(it->second);

           }

//           else
//           {
//        	   cout<<"Required not found"<<endl;
//           }
	}

return 0;

}

// returing the templated map which will be used later for writedata function
template <class key,class T>
map<key,T> Templatedclass<key,T>:: getMapDataBaseWpPoi()
{
	return DatbaseWpPoi;
}

template<class key, class T>
 void Templatedclass<key, T>::clear_T_DB()
{
	DatbaseWpPoi.clear();

}

template <class key,class T>
void Templatedclass<key,T>::printDB()
{
	typename map<key,T> :: iterator it;

	for(it=DatbaseWpPoi.begin();it!=DatbaseWpPoi.end();it++)

	{

		cout<<"The name of the object is"<<it->first<<endl;
	}

}

#endif /* TEMPLATEDCLASS_H_ */
