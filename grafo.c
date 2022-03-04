#include "grafo.h"
#include "pilha.h"
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

void removerVertice(Grafo G, Vertice V) {
    struct noVert *tmp,*q, *aux;
    struct noAdj *p,*temporary;

    if(!strcmp(q->vert.nome,V->nome) && !strcmp(q->vert.tipo, V->tipo) && !strcmp(q->vert.acao, V->acao))
    {
        tmp = q;
        q = q->prox;
    }
    else{
        aux = q;
        while(aux->prox != NULL){
            if(!strcmp(aux->vert.nome,V->nome) && !strcmp(aux->vert.tipo, V->tipo) && !strcmp(aux->vert.acao, V->acao))
                break;
                aux = aux->prox;
        }
        if(aux->prox==NULL){
            return;
        }
        else{
            tmp = aux->prox;
            aux->prox = tmp->prox;
        }
    }
    p = tmp->ladj;
    while(p!=NULL){
        temporary = p;
        p = p->ladj;
        free(temporary);
    }
    G->NumVert--;
    free(tmp);
}

void inserirArco(Grafo G, Vertice v1, Vertice v2, int peso){ 
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

void removerArco(Grafo G, Vertice v1, Vertice v2){
    struct noVert *locu;
    struct Adj *tmp,*q;

    strcpy(locu->vert.nome,v1.nome);
    strcpy(locu->vert.tipo,v1.tipo);
    strcpy(locu->vert.acao,v1.acao);

    if(locu == NULL){
        return;
    }
    if(locu->ladj == NULL){
        return;
    }

    if(!strcmp(locu->vert.nome,v2->nome) && !strcmp(locu->vert.tipo, v2->tipo) && !strcmp(locu->vert.acao, v2->acao)){
        tmp = locu->ladj;
        locu->ladj = locu->ladj->prox;
        free(tmp);
        return;
    }
    q = locu->ladj;
    while(q->ladj != NULL){
        if(!strcmp(q->vert.nome,v2->nome) && !strcmp(q->vert.tipo, v2->tipo) && !strcmp(q->vert.acao, v2->acao)){
            tmp = q->prox;
            q->prox = tmp->prox;
            free(tmp);
            return;
        }
        q = q->prox;
    }
}

int grauVertice(Grafo G, Vertice v) { 
   struct noVert *nv;
   struct noAdj *na;
   int cont = 0;
   if (G == NULL) return 0;
   for (nv = G->vertices; nv!=NULL; nv = nv->prox) {
      if(!strcmp(nv->vert.nome,v->nome) && !strcmp(nv->vert.tipo, v->tipo) && !strcmp(nv->vert.acao, v->acao)){
         for (na = nv->ladj; na != NULL; na = na->prox)
             cont = cont + 1; 
      }
      else{
         for (na = nv->ladj; na != NULL; na = na->prox)
             if(!strcmp(na->vert.nome,v->nome) && !strcmp(na->vert.tipo, v->tipo) && !strcmp(na->vert.acao, v->acao))
               cont = cont + 1;
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

int FoiVisitado(Vertice v, struct noVert *vet, int tam){
   int i;
   for (i = 0; i<=tam; i++){
       if(!strcmp(vet->vert.nome,v->nome) && !strcmp(vet->vert.tipo, v->tipo) && !strcmp(vet->vert.acao, v->acao)) 
       return 1;
   }
   return 0;
}

int imprimeVisita(struct noVert *v, int tam){
  int i;
  printf("\nOrdem da visita: ");
  for (i = 0; i<=tam; i++){
     printf("\nVertice (\"%s\", \"%s\", \"%s\"): ", v->vert.nome, v->vert.tipo, v->vert.acao);
  }
  return 0;
}

void BuscaEmProfundidade (Grafo G, Vertice v) {
   struct noVert *nv;
   struct noAdj *na;
   struct noVert *visitados;
   TipoPilha *pilha;
   int i=0, cont = 0; 
   Vertice vt;

   visitados = (struct noVert *) malloc (G->NumVert * sizeof (struct noVert));
   for (i=0; i<G->NumVert; i++){
      visitados[i] = -1;
   }

   pilha = (TipoPilha *) malloc (sizeof(TipoPilha));
   IniciaPilha(pilha);
   Empilha(v,pilha);
   
   while(!VaziaPilha(pilha)){
       Desempilha(pilha,&vt);
       printf("\nDesempilhou: %d",vt);
       if (FoiVisitado(vt,visitados,cont)==0){
          strcpy(visitados[cont]->vert.nome,vt.nome);
          strcpy(visitados[cont]->vert.tipo,vt.tipo);
          strcpy(visitados[cont]->vert.acao,vt.acao);
          cont++;
          for (nv = G->vertices; nv!=NULL; nv = nv->prox) 
              if(!strcmp(nv->vert.nome,vt->nome) && !strcmp(nv->vert.tipo, vt->tipo) && !strcmp(nv->vert.acao, vt->acao))
                 for (na = nv->ladj; na != NULL; na = na->prox)
                      if (FoiVisitado(na->vert,visitados,cont)==0){
                           Empilha(na->vert,pilha);
                           printf("\nEmpilhou: %d",na->vert);
                      }
       }
   }
   imprimeVisita(visitados,cont-1);
   free(pilha);
}

int procuraMenorDistancia(float *dist, struct noVert *visitado, int NV){
    int i, menor = -1, primeiro = 1;
    Vertice v;
    for(i=0; i < NV; i++){
        if(dist[i] >= 0 && FoiVisitado(v,visitado,NV) == 0){
            if(primeiro){
                menor = i;
                primeiro = 0;
            }else{
                if(dist[menor] > dist[i])
                    menor = i;
            }
        }
    }
    return menor;
}

void menorCaminho_Grafo(Grafo *G, int ini, int *ant, float *dist){
    int i, cont, NV, ind, aux;
    struct noVert *visitado;
    Vertice vert;
    cont = NV = G->NumVert;
    visitado = (struct noVert*) malloc(NV * sizeof(struct noVert));
    for(i=0; i < NV; i++){
        ant[i] = -1;
        dist[i] = -1;
    }
    dist[ini] = 0;
    while(cont > 0){
        aux = procuraMenorDistancia(dist, visitado, NV);
        if(aux -1)
            break;

        cont--;
        for(i=0; i<G->grau[vert]; i++){
            ind = G->arestas[vert][i];
            if(dist[ind] < 0){
               dist[ind] = dist[aux] + 1;
               ant[ind] = aux;
            }else{
                if(dist[ind] > dist[aux] + 1){
                    dist[ind] = dist[aux] + 1;
                    ant[ind] = aux;
                }
            }
        }
    }

    free(visitado);
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
