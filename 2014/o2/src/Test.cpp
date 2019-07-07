/**      
 * @file		Test.cpp
 * @description	Test uygulaması
 * @course		I-B
 * @assignment 	2	
 * @date		21.10.2014
 * @author		İsmet 	GÜZELGÜN	b121210025@sakarya.edu.tr 
 *				İbrahim AKDAĞ		b121210027@sakarya.edu.tr
 *				İlhan Kaya			b121210005@sakarya.edu.tr
 *
 */

#include "Islem.hpp"
int main()
{	
	Islem* s1= new Islem();
	string dd;
	string ff;
	cout<<"x: ";
	cin>>dd;
	cout<<"y: ";
	cin>>ff;
	s1->ilkListeYarat(dd);
	s1->ikinciListeYarat(ff);
	s1->Topla();
	delete s1;
	return 0;
}