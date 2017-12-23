
#include"rsa.h"

int main(int argc,char* argv[])
{
  /*
  RSA receptor(atoi(argv[1]));
  string mensajeCifrado;

  while(true){
    cout<<"mensaje a decifrar \n> ";
	  getline(cin,mensajeCifrado);
	  cout<<receptor.descifrar(mensajeCifrado)<<endl;
  }*/
  /*    
  ZZ e,n;
  e=atoi(argv[1]);
  n=atoi(argv[2]);
  RSA emisor(e,n);
  cout<<emisor.cifrar(argv[3])<<endl;*/
  /*
    cout<<exponenciacion_modular(atoi(argv[1]),atoi(argv[2]),atoi(argv[3]))<<endl;*/
  /*
  int mcd,x,y;
  euclides_extendido(atoi(argv[1]),atoi(argv[2]),mcd,x,y);
  verificar_euclides(atoi(argv[1]),atoi(argv[2]),x,y);
  cout<<"mcd "<<mcd<<"\n"
      <<"x "<<x<<"\n"
      <<"y "<<y<<endl;
  */
  cout<<"haber"<<endl;
  ZZ n;
  n=100;
  ZZ *p;
  cout<<"antes del arreglo"<<endl;
  p=new ZZ[1000000];
  cout<<"vamos a ejecutar"<<endl;
  p=criba_eratostenes(n);
  return 0;
  
}
