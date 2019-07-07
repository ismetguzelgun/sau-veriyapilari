/**      
 * @file		Sirala.cpp
 * @description	Sirala sınıfına ait fonksiyon tanımlamaları ve içerikleri
 * @course		II-A
 * @assignment 	3	
 * @date		10.12.2016
 * @author		
 *								
 *
 */
#include "Sirala.hpp"

Sirala::Sirala(string sr)
{
    ag= new IkiliAramaAgaci();
	this->Oku(sr);
	
}

Sirala::Sirala()
{

}
int Sirala::KarakterdenSayiya(char kr)
{
	int sayi=(int) kr-48;
	if(sayi==-49)
		return 0;
	else
	return sayi;
}
void Sirala::Oku(string)
{
	Kuyruk* kk= new Kuyruk();
	char x;
	kk->KuyrukBaslat();
	ifstream file;
	file.open ("sayilar.txt");
	
	while ( ! file.eof() )
	{
		x = file.get();
		while(x )
		{
			
			if(x=='\n')
				break;
			else 
				kk->Ekle(KarakterdenSayiya(x));
			x = file.get();
			if(file.eof())break;
		}
		this->ag->Ekle(kk);
		while(!kk->BosMu())
		{
			kk->Sil();
		}
	}
	
	//system("cls");
	cout<<"INORDER\n";
	ag->InOrderSirala();
	cout<<"\nPREORDER\n";
	ag->PreOrderSirala();
	cout<<"\nPOSTORDER\n";
	ag->PostOrderSirala();
	//delete kk;
}
Sirala::~Sirala()
{
	delete ag;
}