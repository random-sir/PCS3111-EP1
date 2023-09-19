#include "Integrador.h"

Integrador::Integrador()
{
}

Integrador::~Integrador()
{
}

Sinal *Integrador::processar(Sinal *sinalIN)
{
    int comprimentoOUT = sinalIN->getComprimento();
    double *sequenciaOUT = new double[comprimentoOUT];
    sequenciaOUT[0] = sinalIN->getSequencia()[0];
    for (int i = 1; i < comprimentoOUT; i++)
        sequenciaOUT[i] = sinalIN->getSequencia()[i] + sinalIN->getSequencia()[i - 1]; //funciona pois o index é crescente,
    Sinal *sinalOUT = new Sinal(sequenciaOUT, comprimentoOUT);                         //logo sequenciaOUT[i] é calculado após
    delete[] sequenciaOUT;                                                             //sequenciaOUT[i-1] já ter sido calculado.
    return sinalOUT;
}
