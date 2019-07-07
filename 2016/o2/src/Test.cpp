/**      
 * @file		Test.cpp
 * @description	Test uygulaması
 * @course		II-A
 * @assignment 	2	
 * @date		10.11.2016
 * @author		
 *								
 *
 */

#include "Islem.hpp"
int main()
{	
	Islem* s1= new Islem();
	string list1;
	string list2;
	cout<<"x: ";
	cin>>list1;
	cout<<"y: ";
	cin>>list2;
	s1->ilkListeYarat(list1);
	s1->ikinciListeYarat(list2);
	s1->Topla();
	delete s1;
	return 0;
}