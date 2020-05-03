/*
 * Ficheiro que contém funções gestão das listas
 */

#ifndef _BASE_
#define _BASE_

/* Bibliotecas padrão */
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

/* Bibliotecas próprias */
#include "macro.h"

/*************
* ESTRUTURAS *
*************/

typedef struct Retangulo
{
    int x;        //coordenada canto inferior esquerdo no eixo x
    int y;        //coordenada canto inferior esquerdo no eixo y
    int largura;  //largura do retângulo
    int altura;   //Altura do retângulo
}RETANGULO;

typedef struct noRetangulo
{
    RETANGULO * elemento;           //Aponta para elemento do nó da lista
    struct noRetangulo * proximo;   //Aponta para o proximo nó da lista
}NoRETANGULO;

typedef struct listaRetangulos
{
    int elementos;             //Total de elementos na lista
    NoRETANGULO * cauda;       //Cauda da lista aponta para último elemento inserido na lista
}LISTA_RETANGULOS;

/************
*  HEADERS  *
************/

//Criar elemento retângulo
RETANGULO * criarRetangulo(int x, int y, int largura, int altura);
//Libertar elemento retângulo
int libertarRetangulo(RETANGULO * elemento);
//Criar nó retângulo
NoRETANGULO * criarNoRetangulo(RETANGULO * retangulo);
//Libertar nó retângulo
int libertarNoRetangulo(NoRETANGULO * no);
//Criar lista retângulos
LISTA_RETANGULOS * criarListaRetangulos ();
//Libertar lista retângulos
int libertarListaRetangulos(LISTA_RETANGULOS * lista);
//Adicionar retângulo na lista na posição
int adicionarRetangulo(RETANGULO * retangulo, LISTA_RETANGULOS * lista, int pos);
//Remover retângulo na lista na posição
int removerRetangulo(int pos, LISTA_RETANGULOS * lista);

#endif