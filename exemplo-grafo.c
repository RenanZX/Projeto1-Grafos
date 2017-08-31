#include <stdio.h>
#include <stdlib.h>

/* Estrutura p representar lista de adj do noh*/

struct ListaAdjNo{
    int dest;
    struct ListaAdjNo* next;
};


/* Estrutura p representar lista de adj*/
struct ListAdj{
    struct ListaAdjNo *head; /* ponteiro p o noh 1 */
};


/* estrutura p representar grafo. O grafo eh um array de listas adjacentes */
/* tamanho de array sera V(nro de vertices no grafo)*/
struct Graph{
    int V;
    struct ListAdj* array;
};


/* funcao para criar um lista adjacencia de um noh*/
struct ListaAdjNo* newListAdjNo(int dest){
    struct ListaAdjNo* newNode =
            (struct ListaAdjNo*) malloc(sizeof(struct ListaAdjNo));
    newNode->dest= dest;
    newNode->next = NULL;
    return newNode;
}

/*  funcao que cria um grafo de V vertices*/
struct Graph* createGraph(int V){
    struct Graph* graph= (struct Graph*)malloc(sizeof(struct Graph));
    graph->V=V;

    graph->array=(struct ListAdj*)malloc(V * sizeof(struct ListAdj));

    int i;
    for(i=0; i< V; i++)
        graph->array[i].head = NULL;
    return graph;
};

/* adiciona uma aresta nao direcionada para o grafo. */
void addEdge(struct Graph* graph, int src, int dest)
{
    /* Adiciona uma aresta de src para dest.  Um novo noh eh adicionada para adjacencia */
    /* lista de src.  O noh eh adicionado no inicio */
    struct ListaAdjNo* newNode = newListAdjNo(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    /* Since graph is undirected, add an edge from dest to src also */
    newNode = newListAdjNo(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

/* A utility function to print the adjacenncy list representation of graph */
void printGraph(struct Graph* graph)
{
    int v;
    for (v = 0; v < graph->V; ++v)
    {
        struct ListaAdjNo* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl)
        {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

int main(){

    /* create the graph given in above fugure */
    int V = 5;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    
    
    /* print the adjacency list representation of the above graph */
    printGraph(graph);

return 0;
}