#ifdef _WIN32
    #define limpar "cls"

#elif __linux__
    #define limpar "clear"
  
#endif
#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main()
{
    int op1, op2, peso;
    Grafo g;
    struct vertice ver, ver2;
    do{
        printf("=====================================MENU==============================================\n");
        printf("[1]A\n");
        printf("[2]B\n");
        printf("[3]C\n");
        printf("[4]D\n");
        printf("[5]E\n");
        printf("[6]F\n\n\n");
        printf("[7]PARA SAIR\n\n\n=> ");
    
        scanf("%d",&op1);
        system(limpar);
        setbuf(stdin, NULL);
         
        switch(op1){
            case 1:
            do{
                printf("==============Opções da letra A==============\n[1]Cria grafo\n");
                printf("[2]Insere Vertice\n[3]Remove Vertice\n");
                printf("[4]Insere Aresta\n[5]Remove Aresta\n\n\n");
                printf("[6]PARA SAIR\n\n\n=> ");
                scanf("%d",&op2);
                system(limpar);
                setbuf(stdin, NULL);
                
                switch(op2){
                    case 1:
                        printf("Cria grafo\n");
                        g = criarGrafo();
                    break;
                    
                    case 2:
                        printf("Insere Vertice\n");
                        scanf("%s",ver.nome);
                        scanf("%s",ver.tipo);
                        scanf("%s",ver.acao);
                        inserirVertice(g,&ver);
                        
                        imprimirListaAdj(g); 
                        
                    break;
                    
                    case 3:
                        printf("Remove Vertice\n");
                        printf("Digite o nome do vertice a ser removido: ");
                        scanf("%s",ver.nome);
                        removerVertice (g &ver);
                    break;
                    
                    case 4:
                        printf("Insere Arco\n");
                        printf("Digite o nome do vertice 1: ");
                        scanf("%s",ver.nome);
                        printf("Digite o tipo do vertice 1: ");
                        scanf("%s",ver.tipo);
                        printf("Digite a acao do vertice 1: ");
                        scanf("%s",ver.acao);
                        printf("Digite o nome do vertice 2: ");
                        scanf("%s",ver2.nome);
                        printf("Digite o tipo do vertice 2: ");
                        scanf("%s",ver2.tipo);
                        printf("Digite a acao do vertice 2: ");
                        scanf("%s",ver2.acao);
                        printf("Digite o peso do arco: ");
                        scanf("%d",&peso);
                        inserirArco(g,&ver,&ver2,peso);
                    break;
                    
                    case 5:
                        printf("Remove Arco\n");
                        printf("Digite o nome do vertice 1: ");
                        scanf("%s",ver.nome);
                        printf("Digite o nome do vertice 2: ");
                        scanf("%s",ver2.nome);
                        removerArco(g,&v1,&v2)
                    break;
                }
                
            }while(op2<6);
            break;
        
            case 2:
            printf("busca vertice de maior grau e da a lista de adjacencia\n");
            verticeMaiorGrau(g,&ver);
            imprimirListaAdj(g);
            break;
            
            case 3:
            printf("c\n");
            break;
        
            case 4:
            printf("d\n");
            break;
            
            case 5:
            printf("e\n");
            break;
        
            case 6:
            printf("f\n");
            break;
    
        }
        
    }while(op1<7);

    return 0;
}

    return 0;
}
