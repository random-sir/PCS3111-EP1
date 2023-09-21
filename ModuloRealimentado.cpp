#include "ModuloRealimentado.h"

Sinal* criarSinalAPartirDeElemento(Sinal* sinalIN, int i){  //cria um sinal de comprimento unitário com o elemento [i] em sinalIN.getSequencia

    double sequencia[1];
    sequencia[0] = sinalIN->getSequencia()[i];
    Sinal* sinalOUT = new Sinal(sequencia,1);
    return sinalOUT;
}

ModuloRealimentado::ModuloRealimentado(double ganho)
{
    somadorModuloRealimentado = new Somador;
    inversorModuloRealimentado = new Amplificador(-1);
    pilotoModuloRealimentado = new Piloto(ganho);
}

ModuloRealimentado::~ModuloRealimentado()
{
    delete somadorModuloRealimentado;
    delete inversorModuloRealimentado;
    delete pilotoModuloRealimentado;
}

Sinal *ModuloRealimentado::processar(Sinal *sinalIN)
{
    //inicializacao
    const double velocidadeInicial = 0;
    Sinal* diferenca = nullptr;
    Sinal* saida = nullptr;
    Sinal* saidaInvertida = nullptr;

    //primeira iteracao
    double* sequenciaSaidaInvertida = new double[sinalIN->getComprimento()];
    sequenciaSaidaInvertida[0] = 0;
    diferenca = criarSinalAPartirDeElemento(sinalIN,0);
    saida = pilotoModuloRealimentado->processar(diferenca);
    delete diferenca;
    
    for (int i = 1; i < sinalIN->getComprimento(); i++){
        sequenciaSaidaInvertida = inversorModuloRealimentado->processar(saida[i-1]);
        saidaInvertida = new Sinal(sequenciaSaidaInvertida, i+1); 
        diferenca = somadorModuloRealimentado->processar(sinalIN, saidaInvertida);
        delete saida;
        saida = pilotoModuloRealimentado->processar(diferenca);
        
    }
    return nullptr;
}
