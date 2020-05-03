
/*
 * Ficheiro que contém funções gestão das listas
 */

#include "base.h"


//Criar elemento retângulo
RETANGULO * criarRetangulo(int x, int y, int largura, int altura){
    RETANGULO * novo =calloc(1,sizeof(RETANGULO));
    if(!novo){
        wprintf(L"Erro %d: Impossível alocar memória para novo Retângulo", _ERR_MEMORYALLOC);
        exit(_ERR_MEMORYALLOC);
    }
    novo->x = x;
    novo->y = y;
    novo->largura = largura;
    novo->altura = altura;
    return novo;
}

//Libertar elemento retângulo
int libertarRetangulo(RETANGULO * retangulo){
    if(!retangulo){
        wprintf(L"Erro %d: Impossível libertar elemento retângulo da lista", _ERR_MEMORYFREE);
        return _ERR_MEMORYFREE;
    }
    free(retangulo);
    retangulo = NULL;
    return _SUCESSO;
}

//Criar nó retângulo
NoRETANGULO * criarNoRetangulo(RETANGULO * retangulo){
    NoRETANGULO * novo = calloc(1, sizeof(NoRETANGULO));
    if (!novo){
        wprintf(L"Erro %d: Impossível alocar memória para nó Retângulo", _ERR_MEMORYALLOC);
        exit(_ERR_MEMORYALLOC);
    }
    novo->elemento = retangulo; 
    novo->proximo = novo;
    return novo;
}

//Libertar nó retângulo
int libertarNoRetangulo(NoRETANGULO * no){
    if(!no){
        wprintf(L"Erro %d: Impossível libertar nó da lista", _ERR_MEMORYFREE);
        return _ERR_MEMORYFREE;
    }
    libertarRetangulo(no->elemento);
    free(no);
    no = NULL;
    return _SUCESSO;  
}

//Criar lista retângulos
LISTA_RETANGULOS * criarListaRetangulos (){
    LISTA_RETANGULOS * lista = calloc(1,sizeof(LISTA_RETANGULOS));
    if(!lista){
        wprintf(L"Erro %d: Impossível alocar memória para lista de Retângulos", _ERR_MEMORYALLOC);
        exit(_ERR_MEMORYALLOC);
    }
    lista->elementos = 0;
    lista->cauda = NULL;
    return lista;
}

//Libertar lista retângulos
int libertarListaRetangulos(LISTA_RETANGULOS * lista){
    if(!lista){
        wprintf(L"Erro %d: Impossível libertar lista", _ERR_EMPTYLIST);
        return _ERR_EMPTYLIST;
    }
    while (lista->elementos != 0){
        removerRetangulo(0, lista);
    }
    lista->cauda = NULL;
    free(lista);
    lista = NULL;
    return _SUCESSO;
}

//Adicionar retângulo na lista na posição
int adicionarRetangulo(RETANGULO * retangulo, LISTA_RETANGULOS * lista, int pos){
if (!lista || !retangulo){
        wprintf(L"Erro %d: Impossível adicionar retangulo na lista", _ERR_EMPTYLIST);
        return _ERR_EMPTYLIST;
    }
    if (pos < 0 || pos > lista->elementos){
        wprintf(L"Erro %d: Possição inválida na lista", _ERR_IMPOSSIBLE);
        return _ERR_IMPOSSIBLE;
    }
    NoRETANGULO * no = criarNoRetangulo(retangulo);
    if (lista->elementos == 0){ //Lista vazia adiciona no inicio
        lista->cauda = no;
        lista->elementos++;
    } else if (pos == lista->elementos){   // Adiciona no final
        no->proximo = lista->cauda->proximo; //Aponta novo elemento para o inicio da lista
        lista->cauda->proximo = no;          //Aponta ultimo elemento atual da lista para o novo elemento
        lista->cauda = no;                   //Atualiza o ultimo elemento
        lista->elementos++;
    } else{ //Adiciona na posição
        NoRETANGULO * temp = lista->cauda->proximo;
        for (int i = 0; i < pos; i++)
            temp = temp->proximo;
        no->proximo = temp->proximo; //Aponta novo elemento para o elemento seguinte da posição da lista
        temp->proximo = no;          //Aponta posicao anterior para o novo elemento
        lista->elementos++;
    }
    return _SUCESSO;
}

//Remover retângulo na lista na posição
int removerRetangulo(int pos, LISTA_RETANGULOS * lista){
    if (!lista){
        wprintf(L"Erro %d: Impossível remover lista", _ERR_EMPTYLIST);
        return _ERR_EMPTYLIST;
    }
    if (pos < 0 || pos >= lista->elementos){
        wprintf(L"Erro %d: Possição inválida na lista", _ERR_IMPOSSIBLE);
        return _ERR_IMPOSSIBLE;
    }
    if (pos == 0){ //Remover na cabeça da lista
        NoRETANGULO * temp = lista->cauda->proximo;
        lista->cauda->proximo = temp->proximo; //Aponta final da lista para segundo elemento da lista
        lista->elementos--;
        libertarNoRetangulo(temp);
    } else { //Remove na posição
        NoRETANGULO * temp = lista->cauda->proximo;
        for (int i = 0; i < pos-1; i++)
            temp = temp->proximo;
        NoRETANGULO * aux = temp->proximo;
        temp->proximo = aux->proximo; //Aponta elemento atual para o segundo elemento seguinte da posição da lista
        if (pos == lista->elementos - 1)
            lista->cauda = temp; //Atualiza cauda caso seja o ultimo elemento a remover
        lista->elementos--;
        libertarNoRetangulo(aux);
    }
    return _SUCESSO;
}