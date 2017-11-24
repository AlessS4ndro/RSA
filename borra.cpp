#include "prototipos.h"
#include "definiciones.h"
#include <iostream>

using namespace std;

int main()
{
	ZZ **numeros;
	numeros=new ZZ*[3];
	for(int i=0;i<3;i++)
	  numeros[i]=new ZZ[2];
	
	numeros[0][0]=2;
	numeros[0][1]=3;
	numeros[1][0]=3;
	numeros[1][1]=5;
	numeros[2][0]=2;
	numeros[2][1]=7;

	ZZ *resultado;
	int nfilas=3;
	cout<<"llegamos"<<endl;
	resultado=resto_chino(numeros,nfilas);
	cout<<resultado[0]<<endl;
	cout<<resultado[1]<<endl;
	return 0;
}

