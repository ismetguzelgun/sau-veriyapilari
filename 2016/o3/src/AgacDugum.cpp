/**      
 * @file		AgacDugum.cpp
 * @description	AgacDugum sýnýfýna ait fonksiyon tanýmlamalarý ve içerikleri
 * @course		II-A
 * @assignment 	3	
 * @date		10.12.2016
 * @author		
 *								
 *
 */

#include "AgacDugum.hpp"

AgacDugum::AgacDugum()
{
	agacKuyruk= new Kuyruk();
	agacKuyruk->KuyrukBaslat();
	agacVeri=0;
	sol=NULL;
	sag=NULL;
}
AgacDugum::AgacDugum(Kuyruk*& item)
{
	agacKuyruk= new Kuyruk();
	agacKuyruk=item;
	agacVeri=item->KuyrukDegerleriniTopla();
	sol=NULL;
	sag=NULL;
}

AgacDugum::~AgacDugum()
{
	delete agacKuyruk;
}
