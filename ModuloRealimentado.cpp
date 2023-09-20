#include "ModuloRealimentado.h"

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
    const double velocidadeInicial = 0;
    Sinal* diferenca = nullptr;
    Sinal* saida = nullptr;
    Sinal* saidaInvertida = nullptr;
    double* sequenciaSaidaInvertida = new double[sinalIN->getComprimento()];
    sequenciaSaidaInvertida[0] = 0;
    double* sequenciaDiferenca = new double[1];
    sequenciaDiferenca[0] = sinalIN->getSequencia()[0];
    diferenca = new Sinal(sequenciaDiferenca,1);
    saida = pilotoModuloRealimentado->processar(diferenca);
    delete[] sequenciaDiferenca;
    delete diferenca;
    
    for (int i = 1;i<sinalIN->getComprimento();i++){
        //inversorModuloRealimentado->processar(saida->getSequencia()[i-1]);
    }
    return nullptr;
}
