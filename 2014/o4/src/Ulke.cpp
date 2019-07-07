/**      
 * @file		Ulke.cpp
 * @description	Ulke sınıfına ait fonksiyon tanımlamaları ve içerikleri
 * @course		I-B
 * @assignment 	4	
 * @date		06.12.2014
 * @author		İsmet 	GÜZELGÜN	b121210025@sakarya.edu.tr 
 *				İbrahim AKDAĞ		b121210027@sakarya.edu.tr
 *				Taşkın 	TEMİZ		g101210009@sakarya.edu.tr
 *
 */
#include "Ulke.hpp"
/**
 *Ulke sınıfının kurucu fonksiyonudur.
 *
 */
Ulke::Ulke()
{
	root = NULL;
}
/**
 *dugumKontrol fonksiyonuyla ortaklaşa çalışan bu fonksiyon
 *dugumKontrol fonksiyonu true döndürmesi durumunda aranan degerin
 *hangi dugumde oldugunu bulup o dugumu döndürür.
 *
 */
UlkeDugum* Ulke::dugumAra(string st)
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
 *Aldığı string parametresiyle alınan string ifade
 *agacta var mı yok kontrol eder.Eğer varsa true döndürür.
 *
 */
bool Ulke::dugumKontrol(string st)
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
/**
 *inOrder sıralama yapmak için kullandığımız fonksiyon.
 *public tanımlanmış olup asıl işi yapan inOrderSirala 
 *fonksiyonunu çağırır ve root ile başlar.
 *
 */
void Ulke::inOrder()
{
	inOrderSirala(root);
}
/**
 *inOrder düzende sıralama işini bu fonksiyon üstlenir.
 *Her binary ağacın bir de heapagaci olduğu için yazmakIcinSehirGetir()
 *fonksiyonu ile heapagacinin değerlerini getirir.
 *
 */
void Ulke::inOrderSirala(UlkeDugum* dg)
{
	if(dg!= NULL)
	{
		inOrderSirala(dg->sol);
		cout<<"\n"<<dg->data<<endl;
		dg->yazmakIcinSehirGetir();
		inOrderSirala(dg->sag);
	}
}
/**
 *Dosyadan alınan değerleri ağaçlara yerleştirmek için bu fonksiyon
 *kullanılmaktadır.
 *
 */
void Ulke::yerlestir(UlkeDugum*  dg, string dg2)
{
	if (root == NULL)
	{
		root = dg;
		root->sehirDondur(dg2);
		return;
	}
	else
	{
		UlkeDugum* gecici=root;
		UlkeDugum* dd=NULL;
		bool kontrol=false;
		kontrol=dugumKontrol(dg->data);
		if (kontrol==true)
		{
			dd = dugumAra(dg->data);
			dd->sehirDondur(dg2);
		}
		else
		{
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
						dg->sehirDondur(dg2);

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
						dg->sehirDondur(dg2);
						break;
					}
				}
			}	
		}
	}	
}
/**
 *Ulke sınıfının yıkıcı fonksiyonudur.
 *
 */
Ulke::~Ulke()
{

}