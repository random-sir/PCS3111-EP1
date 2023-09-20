#include "Piloto.h"

Piloto::Piloto(double ganho)
{
    amplificadorPiloto = new Amplificador(ganho);
    integradorPiloto = new Integrador;
}

Piloto::~Piloto()
{
    delete amplificadorPiloto;
    delete integradorPiloto;
}

Sinal *Piloto::processar(Sinal *sinalIN)
{
    Sinal* sinalOUT = new Sinal((integradorPiloto->processar(amplificadorPiloto->processar(sinalIN)))->getSequencia(),sinalIN->getComprimento()); //BUG! Memory leak ainda não consertado!
    return sinalOUT;
}
