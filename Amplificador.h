#include "Sinal.h"
class Amplificador
{
private:
    double ganho;
    Sinal* sinalOUT;
public:
    Amplificador(double ganho);
    virtual ~Amplificador();
    Sinal* processar(Sinal* sinalIN);
    void setGanho(double ganho);
    double getGanho();

};

