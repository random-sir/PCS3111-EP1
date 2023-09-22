#include "ModuloRealimentado.h"

Sinal* ModuloRealimentado::getSinalEspecifico(Sinal* sinalIN, int i){ 
    double sequencia[1];
    sequencia[0] = sinalIN->getSequencia()[i];
    Sinal* sinalOUT = new Sinal(sequencia,1);
    return sinalOUT;
}

ModuloRealimentado::ModuloRealimentado(double ganho){
    somadorModuloRealimentado = new Somador();
    inversorModuloRealimentado = new Amplificador(-1);
    pilotoModuloRealimentado = new Piloto(ganho);
}

ModuloRealimentado::~ModuloRealimentado(){
    delete somadorModuloRealimentado;
    delete inversorModuloRealimentado;
    delete pilotoModuloRealimentado;
}

Sinal *ModuloRealimentado::processar(Sinal *sinalIN){
    //inicializacao
    const double velocidadeInicial = 0;
    Sinal* diferenca = nullptr;
    Sinal* saida = nullptr;
    Sinal* saidaInvertida = nullptr;
    double* sequenciaSaidaInvertida = new double[sinalIN->getComprimento()];

    //primeira iteracao
    sequenciaSaidaInvertida[0] = velocidadeInicial * (-1);
    diferenca = getSinalEspecifico(sinalIN,0);
    saida = pilotoModuloRealimentado->processar(diferenca);
    delete diferenca;

    //iteracoes subsequentes
    for (int i = 1; i < sinalIN->getComprimento(); i++){
        sequenciaSaidaInvertida[i] = ( inversorModuloRealimentado->processar(saida) )->getSequencia()[i-1];
        saidaInvertida = new Sinal(sequenciaSaidaInvertida, i+1); 
        diferenca = somadorModuloRealimentado->processar(saidaInvertida, sinalIN);
        delete saida;
        saida = pilotoModuloRealimentado->processar(diferenca);
        delete saidaInvertida;
        delete diferenca;
    }
    delete[] sequenciaSaidaInvertida;
    return saida;
}
