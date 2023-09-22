#ifndef MODULOREALIMENTADO_H
#define MODULOREALIMENTADO_H
#include "Sinal.h"
#include "Somador.h"
#include "Amplificador.h"
#include "Piloto.h"

class ModuloRealimentado{
private:
    //atributos-circuitos
    Somador *somadorModuloRealimentado;
    Amplificador *inversorModuloRealimentado;
    Piloto *pilotoModuloRealimentado;
    //método de controle interno
    Sinal* getSinalEspecifico(Sinal* sinalIN, int i);
public:
    ModuloRealimentado(double ganho);
    virtual ~ModuloRealimentado();
    Sinal* processar(Sinal* sinalIN);
};

#endif /* MODULOREALIMENTADO_H */
