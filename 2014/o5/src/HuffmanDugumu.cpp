/**
* @file 		HuffmanDugumu.cpp
* @description 	HuffmanDugumu oluşturan cpp dosyası
* @course		1-B
* @assignment	5
* @date			15.12.2014
* @author		İsmet GÜZELGÜN b121210025@sakarya.edu.tr
*		 		İbrahim AKDAĞ  b121210027@sakarya.edu.tr		  
*/
#include "HuffmanDugumu.hpp"
/**
 *HuffmanDugumu kurucusu
 *
 */
HuffmanDugumu::HuffmanDugumu(char kar,int fr)
{
	karakter=kar;
	frekans=fr;
	solDugum=NULL;
	sagDugum=NULL;
	kodKarsiligi="";
}
/**
 *HuffmanDugumu kurucusu
 *
 */
HuffmanDugumu::HuffmanDugumu(char kar,int fr,HuffmanDugumu* sol=NULL,HuffmanDugumu* sag=NULL)
{
	karakter=kar;
	frekans=fr;
	solDugum=sol;
	sagDugum=sag;
	kodKarsiligi="";
}
/**
 *Listenin o dugumumunun yaprak olup olmadıgını kontrol eder
 *
 */
bool HuffmanDugumu::isLeaf()
{
	if(solDugum==NULL && sagDugum==NULL)
		return true;
	
	return false;
}
/**
 *HuffmanDugumu için == operatörünü aşırı yükledik
 *
 */
bool HuffmanDugumu::operator == (HuffmanDugumu& sag)
{
	if(this->karakter == sag.karakter) 
		return true;
	else 
		return false;
}
/**
 *HuffmanDugumu için büyüktür operatörünü aşırı yükledik
 *
 */
bool HuffmanDugumu::operator >(HuffmanDugumu& sag)
{
	if(this->frekans > sag.frekans) 
		return true;
	else 
		return false;
}