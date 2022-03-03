#include "no.h"
#include "vertice.h"

typedef struct Pilha{
   TipoNo *topo;
   int tamanho;
} TipoPilha;

void IniciaPilha(TipoPilha *pilha);
int VaziaPilha(TipoPilha *pilha);
void Empilha(Vertice V, TipoPilha *pilha);
void Desempilha(TipoPilha *pilha, Vertice V);
void Topo (TipoPilha *pilha, Vertice V);