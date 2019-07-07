/**      
 * @file		Test.cpp
 * @description	Test uygulaması
 * @course		I-B
 * @assignment 	1	
 * @date		20.09.2014
 * @author		İsmet	GÜZELGÜN	b121210025@sakarya.edu.tr 
 *				İbrahim	AKDAĞ		b121210027@sakarya.edu.tr
 *
 */

#include "SepetKontrol.hpp"

int main()
{
	char kaynak;
	char hedef;
	int i_kaynak;
	int i_hedef;
	SepetKontrol* sp	=new SepetKontrol();
	
	do{
		system("cls");
		sp->Yazdir();
		cout<<"\nHangi Sepet:";
		cin>>kaynak;
		cout<<"Hangi Sepet ile:";
		cin>>hedef;
		if((kaynak>=65 && kaynak<=67) && (hedef>=65 && hedef<=67))
		{
			i_kaynak=sp->DogruIndexiDondur(kaynak);
			i_hedef=sp->DogruIndexiDondur(hedef);
			sp->Degistir(i_kaynak,i_hedef);
		}

	}while((kaynak!='0')&& (hedef!='0'));
	delete sp;
	return 0;
}