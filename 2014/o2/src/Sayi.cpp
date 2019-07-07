/**      
 * @file		Sayi.cpp
 * @description	Sayi sınıfına ait fonksiyon tanımlamaları ve içerikleri
 * @course		I-B
 * @assignment 	2	
 * @date		21.10.2014
 * @author		İsmet 	GÜZELGÜN	b121210025@sakarya.edu.tr 
 *				İbrahim AKDAĞ		b121210027@sakarya.edu.tr
 *				İlhan Kaya			b121210005@sakarya.edu.tr
 *
 */
 
#include "Sayi.hpp"
/**
 *Parametresiz Sayi kurucu fonksiyon
 *
 */
Sayi::Sayi()
{
	simdiki=new Dugum();
	simdiki=NULL;
}
/**
 *Parametreli Sayi kurucu fonksiyon
 *
 */
Sayi::Sayi(Dugum* dg)
{
	simdiki=new Dugum();
	simdiki=dg;
}
/**
 *Listenin başını gösteren simdiki göstericisi NULL ise liste boş demektir
 *Yani daha gidilebilir.
 */
bool Sayi::VardikMi()
{
	
	return simdiki==NULL;
}
/**
 *Duruma göre ilerlenmesini sağlayan fonksiyon
 *
 */
void Sayi::Ilerle()
{
	if(VardikMi()) cout<<"vardik";
	
	simdiki=simdiki->ileri;
}
/**
 *Hedef düğümdeki dugumverisini getiren fonksiyon
 *
 */
int& Sayi::Getir()
{
	if(simdiki==NULL)	cout<<"bitti";
	//cout<<"-";
	return simdiki->dugumveri;
	
}
/**
 *Yıkıcı fonksiyon
 *
 */
Sayi::~Sayi()
{
	//delete simdiki;
}