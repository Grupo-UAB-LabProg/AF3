#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "model/base.h"


/*TESTE*/

int main(){
    LISTA_RETANGULOS * lista = NULL;
    RETANGULO * retangulo1, * retangulo2;

    lista = criarListaRetangulos();

    retangulo1 = criarRetangulo(10,2,20,10);
    retangulo2 = criarRetangulo(5,2,10,10);
    adicionarRetangulo(retangulo1,lista,lista->elementos);
    adicionarRetangulo(retangulo2,lista,lista->elementos);

    NoRETANGULO * no = lista->cauda;
    for(int i=0;i<lista->elementos;i++){
        wprintf(L"x%d y%d largura%d altura%d\n", no->elemento->x, no->elemento->y,no->elemento->largura,no->elemento->altura);
        no = no->proximo;
    }
    libertarListaRetangulos(lista);
    return 0;
}