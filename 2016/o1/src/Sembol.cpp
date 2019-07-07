/**
 * @file		Sembol.cpp
 * @description	Sembol sınıfı için gerekli üye fonksiyonları içeren kaynak dosyası
 * @course		II-A
 * @assignment 	1
 * @date		19.10.2016
 * @author		
 *
 *
 */
#include "Sembol.hpp"
Sembol::Sembol() 
{
	//sembolNo=sayi;
	this->sembolRenk=0;
	this->sembolTipi=0;
	this->sembol="";

}

//Private değişkenler için
//tanımlanmış setter ve getter fonksiyonlarını tanımlıyoruz
int& Sembol::SembolRenkDondur()
{
	return sembolRenk; 
}
void Sembol::SetSembolRenk(int rasgeleSayi)
{
	this->sembolRenk=rasgeleSayi;
}
int& Sembol::SembolTipiDondur()
{
	return sembolTipi;
}
void Sembol::SetSembolTipi(int sayi)
{
	this->sembolTipi=sayi;
}
string Sembol::SembolDondur()
{
	return sembol;
}
string Sembol::SetSembol(string st)
{
	this->sembol=st;
}
//sembolün tipinin ve renginin belirlenebilmesi için 
//yazılmış fonksiyon
string Sembol::SembolBelirle(int& sayi,int& rasgeleSayi)
{
	//SetSembolRenk(rasgeleSayi);
	this->sembolRenk=rasgeleSayi;
	//SetSembolTipi(sayi);
	this->sembolTipi=sayi;
	
    switch(sembolTipi)
    {
        case 0:
		{
			this->SembolRenkBelirle(sembolRenk);
			return this->sembol=" ♠ ";
            break;
		}

        case 1:
		{
			this->SembolRenkBelirle(sembolRenk);
			return this->sembol=" ♥ ";
            break;
		}

        case 2:
		{
			this->SembolRenkBelirle(sembolRenk);
			return this->sembol=" ♦ ";
            break;
		}

        case 3:
		{
			this->SembolRenkBelirle(sembolRenk);
			return this->sembol=" ♣ ";
            break;
		}

    }
}
//conio.h kütüphanesinden yararlanmak istedim.
//cpp dilinin default olarak renklendirmeye izin vermediğini
//fakat işletim sistemi tarafında bu duruma çözümler sunulduğunu
//gördüm ve windows için tanımlananan msdn fonksiyonlarını kullanmayı
//seçtim.
int& Sembol::SembolRenkBelirle(int& rasgeleSayi)
{

    WORD renk;

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO bufferr;

     //wAttributes word giden yol
	if(GetConsoleScreenBufferInfo(hStdOut, &bufferr))
	{
        
		renk = (bufferr.wAttributes & 0xF0) + (rasgeleSayi & 0x0F);
		SetConsoleTextAttribute(hStdOut, renk);

	}
	return rasgeleSayi;
}
int Sembol::SembolMevcutRenkTut()
{
    static char initialized = 0; // bool
    static WORD attributes;

    if (!initialized) 
	{
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        attributes = csbi.wAttributes;
        initialized = 1;
    }
    return (int)attributes;
}
void Sembol::SembolRenkResetle()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)SembolMevcutRenkTut());
}

