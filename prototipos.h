#ifndef _ALEX_H_
#define _ALEX_H_

#include<NTL/ZZ.h>
#include<iostream>

using namespace NTL;
using namespace std;

template <typename T>
T modulo(T ,T);

template <typename T>
T euclides(T,T);

template <typename T>
bool is_coprimo(T*,int);

template <typename T>
bool and_binari(T);

bool is_primo(int);
bool is_primo(ZZ *,int);

template <typename T>
T exponenciacion_modular(T,T,T);

template <typename T>
void verificar_euclides(T,T,T&,T&);

string num_to_string(ZZ );
string num_to_string(int);

int string_to_int(string );

int ZZ_to_int(ZZ );

template <typename T>
void euclides_extendido(T,T,T &,T &,T &);

template <typename T>

T* resto_chino(T** ,int);

template <typename T>
int number_digits(T);

#endif
