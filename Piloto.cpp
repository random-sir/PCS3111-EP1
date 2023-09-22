#include "Piloto.h"

Piloto::Piloto(double ganho){
    amplificadorPiloto = new Amplificador(ganho);
    integradorPiloto = new Integrador();
}

Piloto::~Piloto(){
    delete amplificadorPiloto;
    delete integradorPiloto;
}

Sinal* Piloto::processar(Sinal *sinalIN){
    //PRECISA CONFERIR PRA VER SE EU NÃO FIZ BOSTA
    Sinal* sinalOUT = new Sinal(sinalIN->getSequencia(), sinalIN->getComprimento());
    sinalOUT = amplificadorPiloto->processar(sinalOUT);
    sinalOUT = integradorPiloto->processar(sinalOUT);
    return sinalOUT;
}
