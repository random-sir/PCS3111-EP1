#ifndef DERIVADOR_H
#define DERIVADOR_H
#include "Sinal.h"
class Derivador
{
private:
    /* data */
public:
    Derivador();
    virtual ~Derivador();
    Sinal* processar(Sinal* sinalIN);
};
#endif