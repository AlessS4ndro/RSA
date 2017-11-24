#ifndef _ALEX_DEFINICION_H_
#define _ALEX_DEFINICION_H_

#include <NTL/ZZ.h>
#include "prototipos.h"
#include <math.h>
#include <iostream>

using namespace std;
using namespace NTL;

template <typename T>
T modulo(T value,T modulo)
{
  T cociente=value/modulo;
  if(value>=0)
    return value-cociente*modulo;
  return modulo-(value*-1+cociente*modulo);
}

template <typename T>
int number_digits(T number)
{
  string palabra=num_to_string(number);
  return palabra.length();
}

template <typename T>
T euclides(T a,T b)
{
  if(b==0)
    return a;
  return euclides(b,modulo(a,b));
}
template <typename T>
bool and_binari(T n)
{
  T cero;
  cero=0;
  if(n==cero)
    return false;
  return true;
}

template <typename T>
void euclides_extendido(T a,T b,T &mcd,T &x,T &y)
{
  T x1,y1;

  if(b==0){
    mcd=a;
    x=1;
    y=0;
  }
  else{
    euclides_extendido(b,modulo(a,b),mcd,x,y);
    x1= x;
    y1=y;
    x=y1;
    y=x1-(a/b)*y1;
  }
}
string num_to_string(ZZ number)
{
  string palabra;
  char numeros[10]={'0','1','2','3','4','5','6','7','8','9'};
  char temp;
  int size;
  ZZ diez;
  diez=10;

  while(number!=0){
    palabra+=numeros[ZZ_to_int(modulo(number,diez))];
    number/=10;
  }
  size=palabra.length();
  for (int i=0;i<size/2;i++){
    temp=palabra[i];
    palabra[i]=palabra[size-i-1];
    palabra[size-i-1]=temp;
  }
  return palabra;
}

string num_to_string(int number)
{
  string palabra;
  char numeros[10]={'0','1','2','3','4','5','6','7','8','9'};
  char temp;
  int size;

  while(number!=0){
    palabra+=numeros[modulo(number,10)];
    number/=10;
  }
  size=palabra.length();
  for (int i=0;i<size/2;i++){
    temp=palabra[i];
    palabra[i]=palabra[size-i-1];
    palabra[size-i-1]=temp;
  }
  return palabra;
}

template <typename T>
bool is_coprimo(T *numbers,int n)
{
  for(int i=0;i<n-1;i++)
    for(int j=i+1;j<n;j++)
      if(euclides(numbers[i],numbers[j])!=1)
	return false;
  return true;
}


bool is_primo(int number)
{
  int i,raizCuadrada;
  raizCuadrada=sqrt(number);
  for(i=2;i<raizCuadrada+1;i++){
    if(modulo(number,i)==0)
      return false;
  }
  if(number==0)
    return false;
  return true;
}
bool is_primo(ZZ number)
{
  ZZ i,raizCuadrada;
  raizCuadrada=SqrRoot(number);
  for(i=2;i<raizCuadrada+1;i++){
    cout<<"calculando divisor... : "<<i<<endl;
    if(modulo(number,i)==0)
      return false;
  }
  if(number==0)
    return false;
  return true;
}

int ZZ_to_int(ZZ number)
{////////// un prerequisito es que number sea de 4 bytes o menos
  unsigned int sumador,crece;
  ZZ conejo,creciente,i;
  sumador=0;
  creciente=1;
  conejo=1;
  crece=1;

  for(i=1;i<NumBits(number)+1;i++){
    creciente=conejo & number;
    if(and_binari(creciente)){
      sumador+=crece;
    }
    else creciente=conejo;
    creciente<<=1;
    conejo=conejo<<1;
    crece<<=1;
  }

  return sumador;
}

template <typename T>
T exponenciacion_modular(T m,T e,T n)
{
  T elevado1,elevado2,resultado,dos;
  dos=2;
  elevado1=m;
  elevado2=1;
  resultado=1;

  while(e!=0){
    elevado1=elevado2=modulo((elevado1*elevado2),n);
    if(modulo(e,dos)==1){
      resultado=modulo((resultado*elevado1),n);
    }
    e/=2;
  }
  return resultado;
}

template <typename T>
T* resto_chino(T** sistema,int nfilas)
{
  T *ps,*as,*qs,*Ps;
  T P,psprima,Xo;
  T *result;
  
  result=new T[2];
  ps=new T[nfilas];
  qs=new T[nfilas];
  as=new T[nfilas];
  Ps=new T[nfilas];
  P=1;
  Xo=0;

  for(int i=0;i<nfilas;i++){
    ps[i]=sistema[i][1];
    as[i]=sistema[i][0];
    P*=ps[i];
  }
  if(!is_coprimo(ps,nfilas))return NULL;
  for(int i=0;i<nfilas;i++){
    Ps[i]=P/ps[i];
    psprima=Ps[i];cout<<"Ps es: "<<Ps[i]<<endl;
    if(Ps[i]>ps[i])
      psprima=modulo(Ps[i],ps[i]);
    T mcd,inversaX,inversaY;
    euclides_extendido(psprima,ps[i],mcd,inversaX,inversaY);
    verificar_euclides(psprima,ps[i],inversaX,inversaY);
    qs[i]=inversaX;cout<<"qs es: "<<qs[i]<<endl;
    Xo+=as[i]*qs[i]*Ps[i];cout<<"Xo es: "<<Xo<<endl;  
  }
  Xo=modulo(Xo,P);
  result[0]=Xo;
  result[1]=P;
  //delete as; delete ps;delete qs;delete Ps;
  return result;
}

int string_to_int(string cadena)
{
  char arreglo[cadena.length()];
  
  for (int i=0;i<cadena.length();i++){
    arreglo[i]=cadena[i];
  }
  return atoi(arreglo);
}

template <typename T >
void verificar_euclides(T a,T b,T &x,T &y)
{
  T mayor;
  if(a<b)mayor=b;
  else mayor=a;  
  if(x<0)x+=mayor;
  if(y<0)y+=mayor;
}
#endif
