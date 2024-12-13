/*To implement Breadth First Search using queue*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct queue
{
    struct node* front;
    struct node* rear;
};

struct queue* create_queue()
{
    struct queue* queue;
    queue=malloc(sizeof(struct queue));
    queue->front=NULL;
    queue->rear=NULL;
    return queue;
}

void enqueue(struct queue* queue,int data)
{
    struct node* new;
    new=malloc(sizeof(struct node));
    new->data=data;
    new->next=NULL;
    /queue empty/
    if(queue->front==NULL)  
    {
        queue->rear=queue->front=new;
    }
    else
    {
        queue->rear->next=new;    
        queue->rear=new;           
    }
}

int dequeue(struct queue* queue)
{
    int data;
    struct node* temp;
    /Queue is empty/
    if(queue->front==NULL)
    {
        return -9999; 
    }
    data=queue->front->data;
    temp=queue->front;
    queue->front=temp->next;
    /whether queue empty after removal/
    if(queue->front==NULL)
    {
        queue->rear=NULL;
    }
    free(temp);
    return data;
}

void bfs(int graph[][5],int vertices,int startvertex)
{
    struct queue* queue;
    int i,currvertex;
    int* visited;
    visited=malloc(vertices*sizeof(int));
    for(i=0;i<vertices;i++)
    {
        visited[i]=0;
    }
    printf("Breadth First Search Traversal starting from %d : ",startvertex);
    queue=create_queue();
    enqueue(queue,startvertex);
    visited[startvertex]=1;
    while(queue->front!=NULL)
    {
        currvertex=dequeue(queue);
        printf("%d ",currvertex);
        for(i=0;i<vertices;i++)
          {
            if(graph[currvertex][i]==1 && visited[i]!=1)
            {
                visited[i]=1;
                enqueue(queue,i);
            }
        }

    }
    free(queue);
    free(visited);
}

void main()
{
    int vertices=5;
    int graph[5][5]={
           {0,1,0,1,0},
           {1,0,1,1,0},
           {0,1,0,1,1},
           {1,1,1,0,1},
           {0,0,1,1,0}
    };
    int vertices=6;
    int graph[6][6] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 1, 0},
        {1, 0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0, 1},
        {0, 1, 1, 0, 0, 1},
        {0, 0, 0, 1, 1, 0}
    };
    int startvertex=0;
    bfs(graph,vertices,startvertex);

}
