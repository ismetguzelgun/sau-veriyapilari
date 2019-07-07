/**      
 * @file		IkiliAramaAgaci.cpp
 * @description	IkiliAramaAgaci sýnýfýna ait fonksiyon tanýmlamalarý ve içerikleri
 * @course		II-A
 * @assignment 	3	
 * @date		10.12.2016
 * @author		
 *								
 *
 */

#include "IkiliAramaAgaci.hpp"

IkiliAramaAgaci::IkiliAramaAgaci()
{
	root=NULL;
}

bool IkiliAramaAgaci::AgacBosMu() const
{
	return (root==NULL);
}

void IkiliAramaAgaci::InOrderSirala() const
{
	InOrder(root);
	
}
void IkiliAramaAgaci::PreOrderSirala() const
{
	PreOrder(root);
	
}
void IkiliAramaAgaci::PostOrderSirala() const
{
	PostOrder(root);
	
}
int IkiliAramaAgaci::AgacBoyu() const
{
	Yukseklik(root);
}
int IkiliAramaAgaci::AgacDugumSayisi() const
{
	DugumSayisi(root);
}
int IkiliAramaAgaci:: AgacDalSayisi() const 
{
	DalSayisi(root);
}

void IkiliAramaAgaci::InOrder(AgacDugum* p) const
{
	if (p != NULL)
	{
		InOrder(p->sol);
		cout << p->agacVeri << " ";
		InOrder(p->sag);
	}	
}
void IkiliAramaAgaci::PreOrder(AgacDugum* p) const
{
	if (p != NULL)
	{
		cout << p->agacVeri << " ";
		InOrder(p->sol);
		InOrder(p->sag);
	}
}
void IkiliAramaAgaci::PostOrder(AgacDugum* p) const
{
	if (p != NULL)
	{

		InOrder(p->sol);
		InOrder(p->sag);
		cout << p->agacVeri << " ";
	}	
}
int IkiliAramaAgaci ::  Yukseklik(AgacDugum* p) const
{
	if(p==NULL)
		return 0;
	else
		return 1+ Max(Yukseklik(p->sol),Yukseklik(p->sag));
}
int IkiliAramaAgaci :: Max(int x, int y) const 
{
	if(x>=y)
		return x;
	else
		return y;
}


void IkiliAramaAgaci :: AgacKopyala(AgacDugum* &kopyalanmisAgacKok, AgacDugum* digerAgacKok)
{
	if(digerAgacKok==NULL)
		kopyalanmisAgacKok==NULL;
	else
	{
		kopyalanmisAgacKok=new AgacDugum();
		kopyalanmisAgacKok->agacVeri=digerAgacKok->agacVeri;
		AgacKopyala(kopyalanmisAgacKok->sol,digerAgacKok->sol);
		AgacKopyala(kopyalanmisAgacKok->sag,digerAgacKok->sag);
	}
	delete kopyalanmisAgacKok;
}
void IkiliAramaAgaci:: YokEt(AgacDugum* &p)
{
	if(p!=NULL)
	{
		YokEt(p->sol);
		YokEt(p->sag);
		delete p;
		p=NULL;
		
	}
}
void IkiliAramaAgaci::AgaciYokEt()
{
	YokEt(root);
}
IkiliAramaAgaci::~IkiliAramaAgaci()
{
	YokEt(root);
}
IkiliAramaAgaci:: IkiliAramaAgaci(const IkiliAramaAgaci& digerAgac)
{
	if(digerAgac.root ==NULL)
		root= NULL;
	else 
		AgacKopyala(root,digerAgac.root);
}
const IkiliAramaAgaci& IkiliAramaAgaci:: operator=(const IkiliAramaAgaci& digerAgac)
{
	if(this!=&digerAgac)
	{
		if(root!=NULL)
			YokEt(root);
		if(digerAgac.root==NULL)
			root=NULL;
		else
			AgacKopyala(root,digerAgac.root);
	}
	return *this;
}

int IkiliAramaAgaci::DugumSayisi(AgacDugum* p) const
{
	
}

int IkiliAramaAgaci::DalSayisi(AgacDugum* p) const
{
	
}

bool IkiliAramaAgaci:: Ara(const int& item) const 
{
	AgacDugum* simdiki;
	bool found=false;
	
	if(root==NULL)
		cout<<"Agac BOS\n";
	else
	{
		simdiki=root;
		while(simdiki!=NULL &&! found)
		{
			if(simdiki->agacVeri==item)
				found=true;
			else if(simdiki->agacVeri>item)
				simdiki=simdiki->sol;
			else
				simdiki=simdiki->sag;
		}
	}
	return found;	
}
void IkiliAramaAgaci:: Ekle( Kuyruk*& item) 
{
	AgacDugum* simdiki;
	AgacDugum* simdikiTakip;
	AgacDugum* yeni;
	yeni=new AgacDugum(item);
	if(root==NULL)
		root=yeni;
	else
	{
		simdiki=root;
		while(simdiki!=NULL)
		{
			simdikiTakip=simdiki;
			if(simdiki->agacVeri==item->KuyrukDegerleriniTopla())
			{
				cout<<"Bu item zaten Agacta{"<<item->KuyrukDegerleriniTopla()<<"}\n";
				return;
			}
			else if(simdiki->agacVeri>item->KuyrukDegerleriniTopla())
				simdiki=simdiki->sol;
			else
				simdiki=simdiki->sag;
		}
		if(simdikiTakip->agacVeri>item->KuyrukDegerleriniTopla())
			simdikiTakip->sol=yeni;
		else
			simdikiTakip->sag=yeni;
	}
}
//void IkiliAramaAgaci:: Olusturucu(