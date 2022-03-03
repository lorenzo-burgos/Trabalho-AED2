#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void IniciaPilha(TipoPilha *pilha){
   pilha->topo = NULL;
   pilha->tamanho = 0;
}

int VaziaPilha(TipoPilha *pilha){
   return (pilha->topo == NULL);
}

void Topo (TipoPilha *pilha, Vertice V){
   TipoNo *aux;
   if (pilha==NULL) 
      return;
   *V = pilha->topo->vert;
}


void Empilha(Vertice V, TipoPilha *pilha){
   TipoNo *aux;
   if (pilha==NULL) 
      return;
   aux = (TipoNo *) malloc(sizeof(TipoNo));
   aux->vert = *V;
   aux->prox = pilha->topo;
   pilha->topo = aux;
   pilha->tamanho++;
}

void Desempilha(TipoPilha *pilha, Vertice V){
   TipoNo *no;
   if (pilha==NULL) 
      return;
   no = pilha->topo;
   *V = no->vert;
   pilha->topo = no->prox;
   pilha->tamanho--;
   free(no);
}