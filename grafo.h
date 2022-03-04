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
void removerArco(Grafo G, Vertice v1, Vertice v2);
void inserirVertice(Grafo G, Vertice V);
void removerVertice(Grafo G, Vertice V);
int grauVertice(Grafo G, Vertice v);
Vertice verticeMaiorGrau(Grafo G, Vertice v);
int FoiVisitado(Vertice v, struct noVert *vet, int tam);
int imprimeVisita(struct noVert *v, int tam);
void imprimirListaAdj(Grafo G);

void BuscaEmProfundidade (Grafo G, Vertice v);
int procuraMenorDistancia(float *dist, struct noVert *visitado, int NV);
void menorCaminho_Grafo(Grafo *G, int ini, int *ant, float *dist);
