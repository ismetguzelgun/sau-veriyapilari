/**
 * @file		Menuler.cpp
 * @description	Menuler sınıfı için gerekli üye fonksiyonları içeren kaynak dosyası
 *				programımızda kapsüllenmenin en iyi şekilde saklanabilmesi için
 *				oluşturulacak kartları bir menü sınıfı altında toplamayı amaç edindim.
 * @course		II-A
 * @assignment 	1
 * @date		19.10.2016
 * @author		
 *
 *
 */
#include "Menuler.hpp"
//parametreli menu kurucu fonksiyonu
Menuler::Menuler(int sayi)
{
	kartAdedi=sayi;
	for(int i=0;i<kartAdedi;i++)
		kartlar[i]= new Kart(i);

}
//menu kurucu fonksiyonu
Menuler::Menuler()
{
	
}

//oluşturulan kartları sembolleriyle ve renkleriyle beraber
//ekrana basan fonksiyon
void Menuler::KartDizisiYaz()
{

	for(int i=0;i<kartAdedi;i++)
	{
		cout<<' '<<i+1<<setw(2);
		//cout<<"\t\t"<<' '<<i+1<<' '<<'\t';
		kartlar[i]->Reset();
		//kartlar[i]->KartIcinSembolDondur()->SembolRenkResetle();
	}
	
	
	cout<<endl;
	for(int i=0;i<kartAdedi;i++)
	{
		kartlar[i]->Reset();
		//kartlar[i]->KartIcinSembolDondur()->SembolRenkResetle();
		if(i<9)
			cout<<kartlar[i]->KartUreteci();
		else
		{
			cout<<setw(6);
			cout<<kartlar[i]->KartUreteci();
			
		}
			
		//cout<<"\t\t"<<kartlar[i]->KartUreteci()<<'\t';
		kartlar[i]->Reset();
		//kartlar[i]->KartIcinSembolDondur()->SembolRenkResetle();
	}

	
	/*
	//Nesneler oluşturulabilmiş mi kontrol etmek amacıyla yazdığım
	//fakat programın aslında görülmesi gerekmeyen küçük bir test
	
	cout<<endl<<"Sembol:";
	//kartlar[0]->SembolRes();
	for(int i=0;i<kartAdedi;i++)
	{
		kartlar[i]->Reset();
		//kartlar[i]->KartIcinSembolDondur()->SembolRenkResetle();
		kartlar[i]->KartIcinSembolAdresiDondur();
		kartlar[i]->Reset();
		//kartlar[i]->KartIcinSembolDondur()->SembolRenkResetle();
	}
		


	//kartlar[0]->SembolRes();
	cout<<endl<<"KartAd:";
	//kartlar[0]->SembolRes();
	for(int i=0;i<kartAdedi;i++)
	{
		kartlar[i]->Reset();
		//kartlar[i]->KartIcinSembolDondur()->SembolRenkResetle();
		cout<<kartlar[i]<<"                   ";
		kartlar[i]->Reset();
		//kartlar[i]->KartIcinSembolDondur()->SembolRenkResetle();
	}
	*/
		
	
	cout<<endl;
}

//menu seçimini kolaylaştırmak için
//yazdığım fonksiyon
void Menuler::MenuSec(int sayi)
{
	
	switch(sayi)
	{
		case 1:
			MenuKartDegistir();
			break;
		case 2:
			MenuTersCevir();
			break;
	}
}
//bizi ilk karşılayan menü
void Menuler::MenuGiris()
{
	system("chcp 65001");
    system("cls");

	
	KartDizisiYaz();
	cout<<endl;
	int ch=0;
	do{
		cout<<"islemler:\n1. Kart Degistir\n2. Ters Cevir\n3. Cikis\n"<<">>";
		cin>>ch;
		MenuSec(ch);
	}while(ch!=3);
}
//kart değiştirilme işleminin yapıldığı menü
void Menuler::MenuKartDegistir()
{
	//system("cls");
	
	cout<<"Kacinci Karti Degistirmek istiyorsun:";
	cin>>this->kartDegistir1;

	cout<<"Hangi Kart ile Degistirmek istiyorsun:";
	cin>>this->kartDegistir2;

	cout<<"Kartlarin Son Hali:\n";
	//kart değiştirme işlemini yapan fonksiyon 
	//aldığı değerleri önce hangikart fonksiyonuna yollayıp
	//döndürdüğü değerleri parametre olarak kullanmak üzere
	//kart değiştir fonksiyonuna atamaktadır.
	KartDegistir(HangiKart(kartDegistir1),HangiKart(kartDegistir2));
	//değişim işlemi bittikten sonra kartdizisi tekrar ekrana basılır.
	KartDizisiYaz();
	
}
//değiştirilmesi istenen kartı bulan fonksiyon
//dizimiz 0 dan başlamakta fakat biz ekrana diziyi basarken
//1 den başlatmaktayız ve kullanıcıdan da aynı şekilde 1..52
//arasında  değer almaktayız.
//işlem görebilmesi için sayi değişkeni 1 değer küçültülür
//örneğin değiştirilmek istenen sayılar için 1 ve 3 değerleri 
//girilmişse aslında bu değerler dizimiz için 0 ve 2 dir
Kart*& Menuler::HangiKart(int sayi)
{
	--sayi;
	
	for(int i=0;i<kartAdedi;i++)
	{
		if(kartlar[i]->KartNumarasiDondur()==sayi)
			return kartlar[i];
		else 
			continue;
	}
}

void Menuler::KartDegistir(Kart*& k1,Kart*& k2)
{

	Kart* temp;
	temp=k2;
	k2=k1;
	k1=temp;

	KartNoDegistir(k1,k2);

}
//kartları değiştirdik fakat
//kart numaralarını değiştirmezsek
//tekrar işleme sokmak istediğimizde eski yerlerinden işlem görecekleri için
//karışıklık olmasın diye kullandığım neredeyse kartdegistir ile
//aynı işi yapan fonksiyon
int*& Menuler::KartNoDegistir(Kart*& k1,Kart*& k2)
{

	
	ch=k2->KartNumarasiDondur();
	k2->KartNumarasiDondur()=k1->KartNumarasiDondur();
	k1->KartNumarasiDondur()=ch;
	
}

//burada öncelikle pointer lar üzerinden ilerleyerek
//eşitlik kurmak kaydıyla yukarıda kartdeğiştir için
//kullandığım basit yer değiştirme algoritmasını kullanmayı düşündüm
//fakat = operatörünü overload etmem gerekti. bundan kaçınarak
//matematik yardımıyla kolayca sorunumu çözdüm.
//hali hazırda 2 kartı değiştirebilen fonksiyonumu yazmıştım.
//örneğin 6 elemanlı bir kartdizisi için bu kartdegistir fonksiyonu
//3 kez çalışacaktı.önce 0 ve 5. sonra 1 ve 4. sonra 2 ve 3. kartları
//değiştirerek sorunumu çözmüş oldum. tek sayılarda ise bu metot sayesindeortanca
//ortanca sayı zaten işlem görmemektedir.örneğin 7 sayısı için 3 kere kartdegistir
//fonksiyonunu çağırmam yeterli olacaktır.
void Menuler::MenuTersCevir()
{

	int adet=kartAdedi;
	int dra=adet;

	int donguSayisi=dra/2;
	donguSayisi++;
	adet++;
	
	for(int i=1;i<donguSayisi;i++)
		KartDegistir(HangiKart(i),HangiKart((adet-i)));
	
	
	KartDizisiYaz();
}
//çöp oluşmaması için kullandığım yıkıcı fonksiyon
Menuler::~Menuler()
{		
	for(int i=0;i<kartAdedi;i++)
		delete kartlar[i];

}