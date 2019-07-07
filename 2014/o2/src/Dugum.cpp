/**      
 * @file		Dugum.cpp
 * @description	Dugum sınıfına ait fonksiyon tanımlamaları ve içerikleri
 * @course		I-B
 * @assignment 	2	
 * @date		21.10.2014
 * @author		İsmet 	GÜZELGÜN	b121210025@sakarya.edu.tr 
 *				İbrahim AKDAĞ		b121210027@sakarya.edu.tr
 *				İlhan Kaya			b121210005@sakarya.edu.tr
 *
 */
 #include "Dugum.hpp"
/**
 *Parametreli Dugum kurucu fonksiyon
 *
 */
Dugum::Dugum(int sayi,Dugum *ilr=NULL)
{
	ileri=ilr;
	dugumveri=sayi;
	d=0;

}
/**
 *Parametresiz Dugum kurucu fonksiyon
 *
 */
Dugum::Dugum()
{
	ileri=NULL;
	//d=0;
}
int& Dugum::Getir()
{
	
	if(d<1)
	{
		d++;
		cout<<"-";
		return dugumveri;
	}
	else
		return dugumveri;
}