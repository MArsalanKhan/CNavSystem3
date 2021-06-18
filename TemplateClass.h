/*
 * TemplateClass.h
 *
 *  Created on: 26 Dec 2015
 *      Author: abd sharaf
 */

#ifndef TEMPLATECLASS_H_
#define TEMPLATECLASS_H_

#include<map>



template<class TKeyValue, class TObject>
class TemplateClass
{

	private :
	std::map<TKeyValue,TObject> TContainer;
public:
	TemplateClass(){};

	void addDatabasePoint( const TObject & poi);
	void MergeContainer(std::map<TKeyValue, TObject> &, std::string);

	TObject* getPointerToDBPoint(std::string name );
	    void  getMapDatabase(std::map<TKeyValue, TObject> &) ;
	    void printDB();

	 ~TemplateClass(){};

};



template< class TKeyValue, class TObject>
TObject* TemplateClass<TKeyValue,TObject> ::getPointerToDBPoint (std::string name)
{
	typename map<TKeyValue, TObject>::iterator i;
	for (i = TContainer.begin(); i != TContainer.end(); i++)
	{
		if (i->second.getName() == name)
		//another approach : using first
		//if(i->first==name)
		{

			return &(i->second);

		}
	}
	return 0;
}


template< class TKeyValue, class TObject>
void TemplateClass<TKeyValue,TObject> ::addDatabasePoint (const TObject& poi)
{

	TContainer.insert(pair<TKeyValue, TObject>(poi.getName(), poi));
}


template< class TKeyValue, class TObject>
void TemplateClass<TKeyValue,TObject> ::MergeContainer(std::map<TKeyValue, TObject> &Filecontainer, std::string MODE){
	if(MODE=="MERGE")

		TContainer.insert(Filecontainer.begin(),Filecontainer.end());
		else
			{TContainer.clear();
			TContainer.insert(Filecontainer.begin(),Filecontainer.end());}
}

template< class TKeyValue, class TObject>
void TemplateClass<TKeyValue,TObject> ::printDB (){

	typename std::map<TKeyValue,TObject> ::iterator It=TContainer.begin();
		for(;It!=TContainer.end();It++)
		{
			It->second.print();
		}
}


template< class TKeyValue, class TObject>
void  TemplateClass<TKeyValue,TObject> ::getMapDatabase(std::map<TKeyValue, TObject> &Mymap) {

	typename map<TKeyValue, TObject>::iterator i1 = TContainer.begin();
		for (; i1!=TContainer.end(); i1++)
		{
			Mymap.insert(pair<TKeyValue, TObject>(i1->first, i1->second));

		}
}


#endif /* TEMPLATECLASS_H_ */
