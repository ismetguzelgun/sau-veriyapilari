/**      
 * @file		Gezici.cpp
 * @description	Gezici sınıfına ait fonksiyon tanımlamaları ve içerikleri
 * @course		II-A
 * @assignment 	2	
 * @date		10.11.2016
 * @author		
 *								
 *
 */
 
#include "Gezici.hpp"
/**
 *Parametresiz Gezici kurucu fonksiyon
 *
 */
Gezici::Gezici()
{
	simdiki=new Dugum();
	simdiki=NULL;
}
/**
 *Parametreli Gezici kurucu fonksiyon
 *
 */
Gezici::Gezici(Dugum* dg)
{
	simdiki=new Dugum();
	simdiki=dg;
}
/**
 *Listenin başını gösteren simdiki göstericisi NULL ise liste boş demektir
 *Yani daha gidilebilir.
 */
bool Gezici::VardikMi()
{
	
	return simdiki==NULL;
}
/**
 *Duruma göre ilerlenmesini sağlayan fonksiyon
 *
 */
void Gezici::Ilerle()
{
	if(VardikMi()) cout<<"vardik";
	
	simdiki=simdiki->ileri;
}
/**
 *Hedef düğümdeki dugumverisini getiren fonksiyon
 *
 */
int& Gezici::Getir()
{
	if(simdiki==NULL)	cout<<"bitti";
	//cout<<"-";
	return simdiki->dugumveri;
	
}
/**
 *Yıkıcı fonksiyon
 *
 */
Gezici::~Gezici()
{
	//delete simdiki;
}