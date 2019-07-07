#ifndef AGAC_HPP
#define AGAC_HPP
#include "Dugum.hpp"

class agac
{
public:
	agac();
	~agac();
	dugum* dugumAra(string);
	bool dugumKontrol(string);
	void inorderT(dugum*,dugum*);
	void inorderTraversal();
	void yerlestir_ulke(string ,string );
private:
	dugum* root;


};
#endif