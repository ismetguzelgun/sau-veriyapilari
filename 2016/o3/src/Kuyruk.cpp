/**      
 * @file		Kuyruk.cpp
 * @description	Kuyruk sýnýfýna ait fonksiyon tanýmlamalarý ve içerikleri
 * @course		II-A
 * @assignment 	3	
 * @date		10.12.2016
 * @author		
 *								
 *
 */
 #include "Kuyruk.hpp"
Kuyruk::Kuyruk()
{
	kuyrukOnu=NULL;
	kuyrukArkasi==NULL;
	kuyrukToplam=0;
}
bool Kuyruk::BosMu() const
{
	return (kuyrukOnu==NULL); 
}
bool Kuyruk::DoluMu() const
{
	return false;
}
void Kuyruk::KuyrukBaslat()
{
	KuyrukDugum* temp;
	while(kuyrukOnu!=NULL)
	{
		temp=kuyrukOnu;
		kuyrukOnu=kuyrukOnu->bag;
		delete temp;
	}
	kuyrukArkasi=NULL;
}
void Kuyruk::Ekle(const int& eleman)
{
	
	yeniDugum=new KuyrukDugum();
	yeniDugum-> dugumVeri=eleman;
	yeniDugum->bag=NULL;
	if(kuyrukOnu==NULL)
	{
		kuyrukOnu=yeniDugum;
		kuyrukArkasi=yeniDugum;
	}
	else
	{
		kuyrukArkasi->bag=yeniDugum;
		kuyrukArkasi=kuyrukArkasi->bag;
	}
	//delete yeniDugum;
}
int Kuyruk::KuyrukOn() const
{
	return kuyrukOnu->dugumVeri;
}
int Kuyruk::KuyrukArka() const
{
	return kuyrukArkasi->dugumVeri;
}

void Kuyruk::Sil()
{
	KuyrukDugum* temp;
	if(!BosMu())
	{
		temp=kuyrukOnu;
		kuyrukOnu=kuyrukOnu->bag;
		delete temp;
		if(kuyrukOnu==NULL)
			kuyrukArkasi==NULL;

	}
	else
		cout<<"Bos kuyruk silemem.\n";
}
int Kuyruk:: KuyrukToplam() const
{
	return kuyrukToplam;
}
int Kuyruk:: KuyrukDegerleriniTopla() 
{
	KuyrukDugum* temp,*temp2;
	temp2=this->kuyrukOnu;
	int sayi=this->KuyrukToplam();
	while(!BosMu())
	{
		sayi+=this->KuyrukOn();
		temp=this->kuyrukOnu;
		temp=temp->bag;
		this->kuyrukOnu=temp;
		//temp;
		//this->kuyrukOnu=this->kuyrukOnu->bag;
	}
	this->kuyrukOnu=temp2;
	//delete temp;
	return sayi;
}
Kuyruk::~Kuyruk()
{
	delete yeniDugum;
}
