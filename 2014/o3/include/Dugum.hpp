#ifndef DUGUM_HPP
#define DUGUM_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;

class dugum
{
public:
	string ulke;
	string sehir;
	dugum* sag_link;
	dugum* sol_link;
	dugum* psehir;
	dugum(string,string);
	dugum(string);
};
#endif