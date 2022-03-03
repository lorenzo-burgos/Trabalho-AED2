#include "vertice.h"

struct grafo {
   int NumVert; 
   int NumArco; 
   struct noVert *vertices; 
};
typedef struct grafo *Grafo;

struct noVert { 
   struct vertice vert; 
   struct noVert *prox;
   struct noAdj *ladj; 
};
typedef struct noVert *Vert;

struct noAdj { 
   struct vertice vert; 
   struct noAdj *prox;
   int peso;
};
typedef struct noAdj *Adj;

struct visitaTempo{
  int vert;
  int tempoDescoberta;
  int tempoFinalizacao;
};


Grafo criarGrafo();
void inserirArco(Grafo G, Vertice v1, Vertice v2, int peso);
void inserirVertice(Grafo G, Vertice V);
int grauVertice(Grafo G, Vertice v);
Vertice verticeMaiorGrau(Grafo G, Vertice v);
void imprimirListaAdj(Grafo G);
void imprimirListaAdjRec(struct noVert *nv);

void BuscaEmLargura(Grafo G, int v);
void BuscaEmProfundidade (Grafo G, int v);
void PercursoProfundidadeTempo (Grafo G, int v);
