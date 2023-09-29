#include "Amplificador.h"
#include "Derivador.h"
#include "Grafico.h"
#include "Integrador.h"
#include "ModuloRealimentado.h"
#include "Piloto.h"
#include "Sinal.h"
#include "Somador.h"
#include <cmath>
#include <iostream>
using namespace std;

Sinal *novoSinal();
void novaOperacao(Sinal *sinalIN);

void menu() {
    /*
     *implementacao da interface
     */
    int opcao;
    Sinal *sinalIN;
    cout << "\tSimulink em C++\nQual simulacao voce gostaria de fazer?\n1) Piloto Automatico\n2) Sua propria sequencia de operacoes\nEscolha: ";
    cin >> opcao;
    cout << endl;
    sinalIN = novoSinal();
    if (opcao == 1) {
        double ganho;
        cout << "Qual o ganho do acelerador?\ng = ";
        cin >> ganho;
        cout << endl;
        ModuloRealimentado *pilotoAutomatico = new ModuloRealimentado(ganho);
        Sinal *sinalOUT = pilotoAutomatico->processar(sinalIN);
        Grafico *grafico = new Grafico("Velocidade do Carro", sinalOUT->getSequencia(), sinalOUT->getComprimento());
        grafico->plot();
        delete grafico;
        delete sinalOUT;
    } else {
        novaOperacao(sinalIN);
    }
}

Sinal *novoSinal() {
    int opcao;
    const int tamanhoMaximo = 60;
    double sequencia[tamanhoMaximo];
    cout << "Qual sinal voce gostaria de utilizar como entrada da sua simulacao?\n1) 5+3*cos(n*pi/8)\n2) constante\n3) rampa\nEscolha: ";
    cin >> opcao;
    cout << endl;
    if (opcao == 1) {
        for (int n = 0; n < tamanhoMaximo; n++) {
            sequencia[n] = 5 + 3 * cos(n * (M_PI / 8));
        }
    }
    else if (opcao == 2) {
        double constante;
        cout << "Qual o valor dessa constante?\nC = ";
        cin >> constante;
        cout << endl;
        for (int n = 0; n < tamanhoMaximo; n++) {
            sequencia[n] = constante;
        }
    } else {
        double inclinacao;
        cout << "Qual a inclinacao dessa rampa?\na = ";
        cin >> inclinacao;
        cout << endl;
        for (int n = 0; n < tamanhoMaximo; n++) {
            sequencia[n] = inclinacao * n;
        }
    }
    Sinal *sinalOUT = new Sinal(sequencia, tamanhoMaximo);
    return sinalOUT;
}
void novaOperacao(Sinal *sinalIN) {
    // implementar uma solucao recursiva
    int opcao;
    Sinal *sinalOUT;
    cout << "Qual operacao voce gostaria de fazer?\n1) Amplificar\n2) Somar\n3) Derivar\n4) Integrar\nEscolha: ";
    cin >> opcao;
    cout << endl;
    if (opcao == 1) {
        double ganho;
        cout << "Qual o ganho dessa amplificação?\ng = ";
        cin >> ganho;
        cout << endl;
        Amplificador *amplificadorOperacao = new Amplificador(ganho);
        sinalOUT = amplificadorOperacao->processar(sinalIN);
        delete amplificadorOperacao;
    }
    if (opcao == 2) {
        Somador *somadorOperacao = new Somador();
        cout << "Informe mais um sinal para ser somado.\n";
        cout << endl;
        Sinal *sinalSomado = novoSinal();
        sinalOUT = somadorOperacao->processar(sinalIN, sinalSomado);
    }
    if (opcao == 3) {
        Derivador *derivadorOperacao = new Derivador();
        sinalOUT = derivadorOperacao->processar(sinalIN);
        delete derivadorOperacao;
    }
    if (opcao == 4) {
        Integrador *integradorOperacao = new Integrador();
        sinalOUT = integradorOperacao->processar(sinalIN);
        delete integradorOperacao;
    }
    cout << "O que voce quer fazer agora?\n1) Realizar mais uma operacao no resultado\n2) Imprimir o resultado para terminar\nEscolha: ";
    cin >> opcao;
    cout << endl;
    if (opcao == 1) {
        novaOperacao(sinalOUT);
    } else {
        Grafico *grafico = new Grafico("Resultado Final", sinalOUT->getSequencia(), sinalOUT->getComprimento());
        grafico->plot();
        delete grafico;
        delete sinalOUT;
    }
}
