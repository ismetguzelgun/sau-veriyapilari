/**
 * @file		Kart.hpp
 * @description	Kart sınıfı için gerekli üye fonksiyonları içeren başlık dosyası
 * @course		II-A
 * @assignment 	1
 * @date		19.10.2016
 * @author		
 *
 *
 */
#ifndef KART_HPP
#define KART_HPP
#include "Sembol.hpp"
class Kart
{
public:
	Kart(int);
	Kart();
	~Kart();
	Sembol*& KartIcinSembolDondur();
	//Test amacıyla yazıldı
	//void KartIcinSembolAdresiDondur();
	string KartUreteci();
	int& KartNumarasiDondur();
	void Reset();

private:
	int kartNo;
	string kartSembol;
	int randTip;
	int randRenk;
	Sembol* semboller;
};
#endif