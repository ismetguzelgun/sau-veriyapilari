#include "Dugum.hpp"
//Kurucu tek parametreli
dugum::dugum(string y)
{
	//ulke=d;
	sehir=y;
	sag_link=NULL;
	sol_link=NULL;
}
//Kurucu iki parametreli
dugum::dugum(string d,string y)
{
	ulke=d;
	psehir=new dugum(y);
	//sehir=psehir->sehir;
	sag_link=NULL;
	sol_link=NULL;
}
