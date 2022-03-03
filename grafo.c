#include "grafo.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Grafo criarGrafo() { 
    Grafo G;
    G = (Grafo) malloc(sizeof (struct grafo));
    if (G!=NULL){
        G->NumArco = 0;
        G->NumVert = 0;
        G->vertices = NULL;
    }   
    return G;
}

void inserirVertice(Grafo G, Vertice V){
    Vert novoVertice;
    Vert nv;
    
    for(nv = G->vertices; nv != NULL; nv = nv->prox)
        if(!strcmp(nv->vert.nome,V->nome) && !strcmp(nv->vert.tipo, V->tipo) && !strcmp(nv->vert.acao, V->acao)) 
            return;
    
    novoVertice = (Vert) malloc (sizeof(struct noVert));
    
    novoVertice->prox = G->vertices;
    G->vertices = novoVertice;
    novoVertice->vert = *V;
    novoVertice->ladj = NULL;
    G->NumVert++;
}

void inserirArco(Grafo G, Vertice v1, Vertice v2, int peso) { 
    struct noVert *v;
    struct noAdj *z;
    struct noAdj *novo = (struct noAdj*) malloc(sizeof (struct noAdj));
    
    if (G == NULL) return;
    
    for (v = G->vertices; v != NULL; v = v->prox) 
        if (!strcmp(v->vert.nome,v1->nome) && !strcmp(v->vert.tipo, v1->tipo) && !strcmp(v->vert.acao, v1->acao)) { 
            for(z = v->ladj; z!= NULL; z = z->prox)
                if (!strcmp(v->vert.nome,v2->nome) && !strcmp(v->vert.tipo, v2->tipo) && !strcmp(v->vert.acao, v2->acao)) return;  
            break;
        }
        novo->prox = v->ladj;
        v->ladj = novo;
        novo->peso = peso;
        novo->vert = *v2;
        G->NumArco++;
}

int grauVertice(Grafo G, Vertice v) { 
   struct noVert *nv;
   struct noAdj *na;
   int cont = 0;
   if (G == NULL) return 0;
   for (nv = G->vertices; nv!=NULL; nv = nv->prox) {
      if(!strcmp(nv->vert.nome,v->nome) && !strcmp(nv->vert.tipo, v->tipo) && !strcmp(nv->vert.acao, v->acao)){
         for (na = nv->ladj; na != NULL; na = na->prox)
             cont = cont + 1;  // grau de saída
      }
      else{
         for (na = nv->ladj; na != NULL; na = na->prox)
             if(!strcmp(na->vert.nome,v->nome) && !strcmp(na->vert.tipo, v->tipo) && !strcmp(na->vert.acao, v->acao))
               cont = cont + 1; // grau de entrada
      }       
   }   
   return cont; 
}

Vertice verticeMaiorGrau(Grafo G, Vertice v){
    
    Vert nv = G->vertices, maiorVert;
    int cont = 0, aux = 0;
    
    if(G == NULL) return 0;
    cont = grauVertice(G,&nv->vert);
    
    aux = cont;
    
    for(maiorVert = nv; nv != NULL; nv = nv->prox){
        cont = grauVertice(G,&nv->vert);
        if(cont > aux){
            maiorVert = nv;
            aux = cont;
        }
    }
    
    *v = maiorVert->vert;
    return v;
    
}


void imprimirListaAdj(Grafo G) { 
    struct noVert *nv;
    struct noAdj *na;
    if (G == NULL)
        return;
    printf("\n\nLista de Adjacencias:");
    for (nv = G->vertices; nv!=NULL; nv = nv->prox) {
        printf("\nVertice (\"%s\", \"%s\", \"%s\"): ", nv->vert.nome, nv->vert.tipo, nv->vert.acao);
        for (na = nv->ladj; na != NULL; na = na->prox)
            printf("(\"%s\", \"%s\", \"%s\") ", na->vert.nome, na->vert.tipo, na->vert.acao); 
    }
    printf("\n\n");
}


