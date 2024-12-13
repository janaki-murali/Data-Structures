/*To represent Adjacency List for graph using linked list*/

#include <stdio.h>
#include <stdlib.h>
  
struct node
{
    int vertex;
    struct node* link;
};

struct graph
{
    int vertices;
    struct node** adjarr;
};


struct node* create_node(int vertex)
{
    struct node* new;
    new=malloc(sizeof(struct node));
    new->vertex=vertex;
    new->link=NULL;
    return new;
}

struct graph* create_graph(int v)
{
    struct graph* graph;
    graph=malloc(sizeof(struct graph));
    graph->vertices=v;
    graph->adjarr=(struct node*)malloc(v*sizeof(struct node));
    for(int i=0;i<v;i++)
    {
        graph->adjarr[i]=NULL;
    }
    return graph;
}

void insert_undirected(struct graph* graph,int s,int d)
{
    struct node* new;
    new=create_node(d);
    new->link=graph->adjarr[s];
    graph->adjarr[s]=new;
    new=create_node(s);
    new->link=graph->adjarr[d];
    graph->adjarr[d]=new;    
}

void insert_directed(struct graph* graph,int s,int d)
{
    struct node* new;
    new=create_node(d);
    new->link=graph->adjarr[s];
    graph->adjarr[s]=new;
}

//function for display
void display(struct graph* graph)
{
    struct node* ptr;
    for(int i=0;i<graph->vertices;i++)
    {
        printf("Adjacent List of Vertex  %d : ",i);
        ptr=graph->adjarr[i];
        while(ptr)
        {
            printf("%d  -> ",ptr->vertex);
            ptr=ptr->link;
        }
        printf("NULL\n");
    }
}

void main()
{
    struct graph* graph;
    int vertex,edges,s,d,isdirect;
    printf("How many vertices ? : ");
    scanf("%d",&vertex);
    graph=create_graph(vertex);
    printf("Enter 1 for a directed graph or 0 for an undirected graph: ");
    scanf("%d",&isdirect);
    printf("How many edges ? : ");
    scanf("%d",&edges);
    printf("Enter the edges(source destination)\n");
    for(int i=1;i<=edges;i++)
    {
        printf("Edge %d: ", i);
        scanf("%d %d",&s,&d);
        if(isdirect)
        {
            insert_directed(graph,s,d);
        }
        else
        {
            insert_undirected(graph,s,d);
        }
    }
    printf("\nAdjacency List Representation of the Graph:\n");
    display(graph);
}
