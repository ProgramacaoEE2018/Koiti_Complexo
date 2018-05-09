#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

class Complexo{
private:
    float real, im;
public:
    Complexo(float a, float b);

    float Modulo(){
        return sqrt(real*real+im*im);
    }

    Complexo Conjugado(){
        return Complexo(real, (-1)*im);
    }

    Complexo Diferenca(Complexo omega){
        return Complexo(real - omega.real, im - omega.im);
    }

    Complexo Soma(Complexo omega){
        return Complexo(real + omega.real, im + omega.im);
    }

    Complexo Produto(Complexo omega){
        return Complexo(real*omega.real-im*omega.im, real*omega.im+im*omega.real);
    }

    Complexo Divisao(Complexo omega){
        return Complexo((real*omega.real+im*omega.im)/(omega.real*omega.real+omega.im*omega.im), (im*omega.real-real*omega.im)/(omega.real*omega.real+omega.im*omega.im));
    }

    void imprimir_cartesiana(){
        printf("%f %f\n", real, im);
    }
};

Complexo::Complexo(float a, float b){
    real = a;
    im = b;
}

int main()
{
     Complexo z(3,4);
     Complexo z1(3,0);

     printf("%f\n", z.Modulo());

     Complexo sum = z.Soma(z1);
     sum.imprimir_cartesiana();

     Complexo dif = z.Diferenca(z1);
     dif.imprimir_cartesiana();

     Complexo prod = z.Produto(z1);
     prod.imprimir_cartesiana();

     Complexo div = z.Divisao(z1);
     div.imprimir_cartesiana();
}
