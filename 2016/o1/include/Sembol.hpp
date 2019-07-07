/**
 * @file		Sembol.hpp
 * @description	Sembol sınıfı için gerekli üye fonksiyonları içeren başlık dosyası
 * @course		II-A
 * @assignment 	1
 * @date		19.10.2016
 * @author		
 *
 *
 */
#ifndef SEMBOL_HPP
#define SEMBOL_HPP
#include <iostream>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <windows.h>   // WinApi header

using namespace std;
/*const char* MACA=" ♠ ";
const char* KUPA=" ♥ ";
const char* KARO=" ♦ ";
const char* SINEK=" ♣ ";*/
class Sembol
{
public: 

	Sembol();

	//setter ve getter fonskyionlar
	int& SembolRenkDondur();
	void SetSembolRenk(int); 
	
	int& SembolTipiDondur();
	void SetSembolTipi(int);
	
	string SembolDondur();
	string SetSembol(string);

    //sembol rengi ve tipi için
	//gereken fonksiyonlar
	string SembolBelirle(int&,int&);
	int& SembolRenkBelirle(int&);
    int SembolMevcutRenkTut();
	void SembolRenkResetle();
private:
	string sembol;
    int sembolRenk;
    int sembolTipi;
	
};
#endif
