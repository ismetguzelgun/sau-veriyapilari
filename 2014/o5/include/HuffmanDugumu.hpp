/**
* @file			HuffmanDugumu.hpp
* @description 	HuffmanDugumu s�n�f�n� tan�mlayan hpp dosyas�
* @course		1-B
* @assignment	5
* @date			12.12.2014
* @author		�smet G�ZELG�N b121210025@sakarya.edu.tr
*				�brahim AKDA�  b121210027@sakarya.edu.tr		  
*/
#ifndef HUFFMANDUGUMU_HPP
#define HUFFMANDUGUMU_HPP
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <cmath>
using namespace std;

class HuffmanDugumu
{
public:
	char karakter;
	int frekans;	
	string kodKarsiligi; 	
	HuffmanDugumu* solDugum;
	HuffmanDugumu* sagDugum;
	
	HuffmanDugumu(char ,int , HuffmanDugumu*,HuffmanDugumu* );
	HuffmanDugumu(char ,int );
	bool isLeaf();
	bool operator==(HuffmanDugumu&);
	bool operator>(HuffmanDugumu&);
};
#endif