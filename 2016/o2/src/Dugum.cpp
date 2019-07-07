/**      
 * @file		Dugum.cpp
 * @description	Dugum sınıfına ait fonksiyon tanımlamaları ve içerikleri
 * @course		II-A
 * @assignment 	2	
 * @date		10.11.2016
 * @author		
 *								
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
}
/**
 *Parametresiz Dugum kurucu fonksiyon
 *
 */
Dugum::Dugum()
{
	ileri=NULL;
	
}
int& Dugum::Getir()
{
	return dugumveri;
}