//#include "Kart.hpp"
#include "Menuler.hpp"
int main()
{
	int sayi=-1;
	cout<<"Kart Adedi(maks 52):";
	cin>>sayi;
	
	srand (time(NULL));
	Menuler* mn=  new Menuler(sayi);
	mn->MenuGiris();

	delete mn;
    return 0;

}
