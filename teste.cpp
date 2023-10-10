#include "Amplificador.h"
#include "Derivador.h"
#include "Grafico.h"
#include "Integrador.h"
#include "ModuloRealimentado.h"
#include "Piloto.h"
#include "Sinal.h"
#include "Somador.h"
#include <iostream>
using namespace std;

/*FUNÇÕES PARA TESTAR AS CLASSES*/
/*TESTE DE MENU FAREMOS USANDO EP < ENTRADA.TXT > SAIDA.TXT*//*COMO O JUDGE JÁ TESTA A CHAMADA DE TODOS OS MÉTODOS, VAMOS TESTAR ERROS E PONTOS EXTREMOS AQUI*/

void testaSinal(){
    double seq1[60];
    double seq2[1] = {7.89};//unitário
    double seq3[60];
    double seq4[60];
    double seq5[60];
    double seq6[30];
    
    srand(time(NULL));

    for(int i = 0; i < 60; i++){
        i <= 10 ? seq1[i] = i : seq1[i] = 10; //normal
        seq3[i] = M_PI; //constante
        seq4[i] = 0; //neutro
        i <= 10 ? seq5[i] = -i : seq5[i] = -10; //negativo
        if(i < 30){
          seq6[i] =  rand() % 10;
        }
    }

    Sinal *sinal1 = new Sinal(seq1,60);
    sinal1->imprimir("1");
    Sinal *sinal2 = new Sinal(seq2,1);
    sinal2->imprimir("2");
    Sinal *sinal3 = new Sinal(seq3,60);
    sinal3->imprimir("3");
    Sinal *sinal4 = new Sinal(seq4,60);
    sinal4->imprimir("4");
    Sinal *sinal5 = new Sinal(seq5,60);
    sinal5->imprimir("5");
    Sinal *sinal6 = new Sinal(seq6,60);
    sinal6->imprimir("6");

    delete sinal1;
    delete sinal2;
    delete sinal3;
    delete sinal4;
    delete sinal5;
    delete sinal6;
}

void testaSomador(){
    double seq1[60];
    double seq2[1] = {7.89};//unitário
    double seq3[60];
    double seq4[60];
    double seq5[60];

    for(int i = 0; i < 60; i++){
        i <= 10 ? seq1[i] = i : seq1[i] = 10; //normal
        seq3[i] = M_PI; //constante
        seq4[i] = 0; //neutro
        i <= 10 ? seq5[i] = -i : seq5[i] = -10; //negativo
    }

    Sinal *sinal1 = new Sinal(seq1,60);
    Sinal *sinal2 = new Sinal(seq2,1);
    Sinal *sinal3 = new Sinal(seq3,60);
    Sinal *sinal4 = new Sinal(seq4,60);
    Sinal *sinal5 = new Sinal(seq5,60);

    Somador *sum = new Somador();

    Sinal *s1 = sum->processar(sinal1,sinal1);//dois normais
    s1->imprimir("1");
    Sinal *s2 = sum->processar(sinal1,sinal4);//normal e neutro
    s2->imprimir("2");
    Sinal *s3 = sum->processar(sinal2,sinal1);//tamanhos diferentes
    s3->imprimir("3");
    Sinal *s4 = sum->processar(sinal1,sinal5); //neutralizar sinais
    s4->imprimir("4");
    Sinal *s5 = sum->processar(sinal1,sinal3); //normal e constante
    s5->imprimir("5");

    delete s1;
    delete s2;
    delete s3;
    delete s4;
    delete s5;

    delete sinal1;
    delete sinal2;
    delete sinal3;
    delete sinal4;
    delete sinal5;
    delete sum;
}

void testaDerivador(){
    return void;
}

void testaIntegrador(){
    return void;
}

void testaAmplificador(){
    double seq1[60];
    double seq2[1] = {7.89};//unitário
    double seq3[60];
    double seq4[60];
    double seq5[60];
    double seq6[30];
    
    srand(time(NULL));

    for(int i = 0; i < 60; i++){
        i <= 10 ? seq1[i] = i : seq1[i] = 10; //normal
        seq3[i] = M_PI; //constante
        seq4[i] = 0; //neutro
        i <= 10 ? seq5[i] = -i : seq5[i] = -10; //negativo
        if(i < 30){
          seq6[i] =  rand() % 10;
        }
    }

    Sinal *sinal1 = new Sinal(seq1,60);
    Sinal *sinal2 = new Sinal(seq2,1);
    Sinal *sinal3 = new Sinal(seq3,60);
    Sinal *sinal4 = new Sinal(seq4,60);
    Sinal *sinal5 = new Sinal(seq5,60);
    Sinal *sinal6 = new Sinal(seq6,30);


    {Amplificador *ampl1 = new Amplificador(0); //amplificagem com 0
    Sinal *sinal11 = ampl1->processar(sinal1);//amplificagem com 0 no sinal1
    sinal11->imprimir("###############################");
    Sinal *sinal22 = ampl1->processar(sinal2);//amplificagem com 0 no sinal2
    sinal22->imprimir("###############################");
    Sinal *sinal33 = ampl1->processar(sinal3);//amplificagem com 0 no sinal3
    sinal33->imprimir("###############################");
    Sinal *sinal44 = ampl1->processar(sinal4);//amplificagem com 0 no sinal4
    sinal44->imprimir("###############################");
    Sinal *sinal55 = ampl1->processar(sinal5);//amplificagem com 0 no sinal5
    sinal55->imprimir("###############################");
    Sinal *sinal66 = ampl1->processar(sinal6);//amplificagem com 0 no sinal6
    sinal66->imprimir("###############################");

    delete sinal11;
    delete sinal22;
    delete sinal33;
    delete sinal44;
    delete sinal55;
    delete sinal66;
    delete ampl1;}

    {Amplificador *ampl2 = new Amplificador(1); //amplificagem com 1
    Sinal *sinal11 = ampl2->processar(sinal1);//amplificagem com 1 no sinal1
    sinal11->imprimir("###############################");
    Sinal *sinal22 = ampl2->processar(sinal2);//amplificagem com 1 no sinal2
    sinal22->imprimir("###############################");
    Sinal *sinal33 = ampl2->processar(sinal3);//amplificagem com 1 no sinal3
    sinal33->imprimir("###############################");
    Sinal *sinal44 = ampl2->processar(sinal4);//amplificagem com 1 no sinal4
    sinal44->imprimir("###############################");
    Sinal *sinal55 = ampl2->processar(sinal5);//amplificagem com 1 no sinal5
    sinal55->imprimir("###############################");
    Sinal *sinal66 = ampl2->processar(sinal6);//amplificagem com 1 no sinal6
    sinal66->imprimir("###############################");

    delete sinal11;
    delete sinal22;
    delete sinal33;
    delete sinal44;
    delete sinal55;
    delete sinal66;
    delete ampl2;}

    {Amplificador *ampl3 = new Amplificador(-1); //amplificagem com negativo -1 
    Sinal *sinal11 = ampl3->processar(sinal1);//amplificagem com -1 no sinal1
    sinal11->imprimir("###############################");
    Sinal *sinal22 = ampl3->processar(sinal2);//amplificagem com -1 no sinal2
    sinal22->imprimir("###############################");
    Sinal *sinal33 = ampl3->processar(sinal3);//amplificagem com -1 no sinal3
    sinal33->imprimir("###############################");
    Sinal *sinal44 = ampl3->processar(sinal4);//amplificagem com -1 no sinal4
    sinal44->imprimir("###############################");
    Sinal *sinal55 = ampl3->processar(sinal5);//amplificagem com -1 no sinal5
    sinal55->imprimir("###############################");
    Sinal *sinal66 = ampl3->processar(sinal6);//amplificagem com -1 no sinal5
    sinal66->imprimir("###############################");

    delete sinal11;
    delete sinal22;
    delete sinal33;
    delete sinal44;
    delete sinal55;
    delete sinal66;
    delete ampl3;}

    {Amplificador *ampl4 = new Amplificador(2.3); //amplificagem com positivo qualquer
    Sinal *sinal11 = ampl4->processar(sinal1);//amplificagem com positivo qualquer no sinal1
    sinal11->imprimir("###############################");
    Sinal *sinal22 = ampl4->processar(sinal2);//amplificagem com positivo qualquer no sinal2
    sinal22->imprimir("###############################");
    Sinal *sinal33 = ampl4->processar(sinal3);//amplificagem com positivo qualquer no sinal3
    sinal33->imprimir("###############################");
    Sinal *sinal44 = ampl4->processar(sinal4);//amplificagem com positivo qualquer no sinal4
    sinal44->imprimir("###############################");
    Sinal *sinal55 = ampl4->processar(sinal5);//amplificagem com positivo qualquer no sinal5
    sinal55->imprimir("###############################");
    Sinal *sinal66 = ampl4->processar(sinal6);//amplificagem com positivo qualquer no sinal6
    sinal66->imprimir("###############################");

    delete sinal11;
    delete sinal22;
    delete sinal33;
    delete sinal44;
    delete sinal55;
    delete sinal66;
    delete ampl4;}

    {Amplificador *ampl5 = new Amplificador(-3.4); //amplificagem com negativo qualquer 
    Sinal *sinal11 = ampl5->processar(sinal1);//amplificagem com negativo qualquer no sinal1
    sinal11->imprimir("###############################");
    Sinal *sinal22 = ampl5->processar(sinal2);//amplificagem com negativo qualquer no sinal2
    sinal22->imprimir("###############################");
    Sinal *sinal33 = ampl5->processar(sinal3);//amplificagem com negativo qualquer no sinal3
    sinal33->imprimir("###############################");
    Sinal *sinal44 = ampl5->processar(sinal4);//amplificagem com negativo qualquer no sinal4
    sinal44->imprimir("###############################");
    Sinal *sinal55 = ampl5->processar(sinal5);//amplificagem com negativo qualquer no sinal5
    sinal55->imprimir("###############################");
    Sinal *sinal66 = ampl5->processar(sinal6);//amplificagem com negativo qualquer no sinal5
    sinal66->imprimir("###############################");

    delete sinal11;
    delete sinal22;
    delete sinal33;
    delete sinal44;
    delete sinal55;
    delete sinal66;
    delete ampl5;}

    delete sinal1;
    delete sinal2;
    delete sinal3;
    delete sinal4;
    delete sinal5;
    delete sinal6;
}

void testaPiloto(){
    return void;
}

void testaModuloRealimentado(){
    return void;
}

