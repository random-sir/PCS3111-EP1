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
    //só deixei a lógica mais clara. AINDA EM REFORMA, PROVAVELMENTE AINDA POSSUI ERROS.
    Sinal* sinalOUT = new Sinal(sinalIN->getSequencia(), sinalIN->getComprimento());
    sinalOUT = amplificadorPiloto->processar(sinalOUT);
    sinalOUT = integradorPiloto->processar(sinalOUT);
    return sinalOUT;
}
