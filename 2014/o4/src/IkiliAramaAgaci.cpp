/**      
 * @file		IkiliAramaAgaci.cpp
 * @description	IkiliAramaAgaci sınıfına ait fonksiyon tanımlamaları ve içerikleri
 * @course		I-B
 * @assignment 	4	
 * @date		06.12.2014
 * @author		İsmet 	GÜZELGÜN	b121210025@sakarya.edu.tr 
 *				İbrahim AKDAĞ		b121210027@sakarya.edu.tr
 *				Taşkın 	TEMİZ		g101210009@sakarya.edu.tr
 *
 */
#include "IkiliAramaAgaci.hpp"
/**
 *IkiliAramaAgaci sınıfının kurucu fonksiyonudur.
 *
 */
IkiliAramaAgaci::IkiliAramaAgaci()
{
	root=NULL;
}
/**
 *IkiliAramaAgaci sınıfının yıkıcı fonksiyonudur.
 *
 */
IkiliAramaAgaci::~IkiliAramaAgaci()
{
	delete root;
}
/**
 *IkiliAramaAgaci inOrder siralama fonksiyonunu çağıran
 *fonksiyon.Başlangıç düğümü olarak root verir bu sayede 
 *tüm dugumler gezilebilir.
 *
 */
void IkiliAramaAgaci::inOrder()
{
	inOrderSirala(root);
}
/**
 *IkiliAramaAgacini inOrder siralayan fonksiyon
 *
 */
void IkiliAramaAgaci::inOrderSirala(UlkeDugum* dg)
{
	if(dg!= NULL)
	{
		inOrderSirala(dg->sol);
		cout<<dg->data<<endl;
		inOrderSirala(dg->sag);
	}
}
/**
 *Dışarıdan girilen değerleri ağaca yerleştiren fonksiyon
 *
 */
void IkiliAramaAgaci::yerlestir(UlkeDugum* dg)
{
	if (root == NULL)
	{
		root = dg;
		return;
	}
	UlkeDugum* gecici=root;
	while(true)
	{
		if (dg->data.compare(gecici->data) < 0)
		{
			if (gecici->sol != NULL)
			{
				gecici = gecici->sol;
			}
			else
			{
				gecici->sol = dg;
				break;
			}
		}
		else 
		{
			if (gecici->sag != NULL)
			{
				gecici = gecici->sag;
			}
			else
			{
				gecici->sag = dg;
				break;
			}
		}
	}	
}
/**
 *Dışarıdan girilen değer eğer dugumKontrol() fonksiyonu true dönmüşse
 *var demektir.Bu durumda var olan düğümün hangisi olduğunu bulup o düğümü
 *döndüren fonksiyon.
 *
 */
UlkeDugum* IkiliAramaAgaci::dugumAra(string st)
{
	UlkeDugum* cr;
	if (root == NULL)
		cout << "olmadi";
	else
	{
		cr = root;
		while (cr!=NULL)
		{
			if (st.compare(cr->data) == 0)
				return cr;
			else if (st.compare(cr->data)<0)
				cr = cr->sol;
			else 
				cr = cr->sag;
		}
	}
}
/**
 *Dışarıdan girilen değer daha öncede girilmiş ve düğümlere yerleştirilmiş mi 
 *kontrol eden fonksiyon.
 *
 */
bool IkiliAramaAgaci::dugumKontrol(string st)
{
	UlkeDugum* cr;
	bool found = false;
	if (root == NULL)
		cout << "olmadi";
	else
	{
		cr = root;
		while (cr != NULL && found != true)
		{
			if (st.compare(cr->data) == 0)
				found = true;
			else if (st.compare(cr->data)<0)
				cr = cr->sol;
			else if (st.compare(cr->data)>0)
				cr = cr->sag;
			else
				break;

		}
	}
	return found;
}