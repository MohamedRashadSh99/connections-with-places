#include <stdio.h>
#include <stdlib.h>
//queue implementation...............
typedef struct
{
    int front,rear,numberItems;
    int Capacity;
    int *items;
} Queue;
void initialize(Queue *q,int size)
{
    q->rear=0;
    q->front=0;
    q->numberItems=0;
    q->Capacity=size;
    q->items=(int*)malloc(size*sizeof(int));
}


void enqueue(Queue *q,int value)
{
    q->items[q->rear]=value;
    q->rear=(q->rear+1)%q->Capacity;
    q->numberItems++;
}
int dequeue(Queue *q)
{
    int data=q->items[q->front];
    q->front=(q->front+1)%q->Capacity;
    q->numberItems--;
    return data;
}


int isempty(Queue *q)
{
    if(q->numberItems==0)
        return 1;
    else
        return 0 ;
}
int n(Queue *q)
{
    return q->numberItems;
}
int isfull(Queue *q)
{
    if(q->numberItems==q->Capacity)
        return 1;
    else
        return 0 ;
}
////part1....................................
void display(Queue *q)
{
    Queue copy;
    initialize(&copy,q->Capacity);
    printf("[");
    while (!isempty(q))
    {
        int x=dequeue(q);
        printf("%d ",x);
        enqueue(&copy,x);
    }
    printf("]\n");
    while (!isempty(&copy))
        enqueue(q,dequeue(&copy));
}
void display_our_array(int*arr,int n)
{
    int j;
    printf("our array:\n");
    for(j=0; j<n; j++)
    {
        printf("%d ",arr[j]);
    }
}
int put_neighbour(int vertices,int arr_graph[vertices][vertices],int *arr,int vertix,int k)
{
    int i,temp,number,x,count;
    count=0;
    temp=k;
    Queue q;
    initialize(&q,vertices);
    enqueue(&q,vertix-1);
    number=n(&q);

    while(k!=0)
    {
        number=n(&q);
        while(number!=0)
        {
            x=dequeue(&q);
            for(i=0; i<vertices; i++)
            {
                if(arr_graph[x][i]==1&&arr[i]==-1)

                {
                    if(k==1)
                        count++;
                    arr[i]=temp-k+1;
                    enqueue(&q,i);
                }
            }
            number--;
        }
        k--;

    }
    return count;
}
int*make_initial_graph(int vertices,int*graph[vertices][vertices])
{
    int iloop,jloop;
    for( iloop=0; iloop<vertices; iloop++)
    {
        for(jloop=0; jloop<vertices; jloop++)
        {
            graph[iloop][jloop]=0;
        }
    }
}
void print_graph(int v,int*graph[v][v])
{
    int iloop,jloop;
    printf("our graph\n");
    for( iloop=0; iloop<v; iloop++)
    {
        for(jloop=0; jloop<v; jloop++)
        {
            printf("%d ",graph[iloop][jloop]);
        }
        printf("\n");
    }
}
void make_initial_arra(int *arr,int v)
{
    int jloop;
    for(jloop=0; jloop<v; jloop++)
    {
        arr[jloop]=-1;
    }
}
void Q1()
{
    int vertices,edges,iloop,jloop,iindex,jindex,scan;
    printf("please enter the number of vertices:");
    scanf("%d",&vertices);
    printf("please enter the number of edges:");
    scanf("%d",&edges);
    int graph[vertices][vertices];
    int arr[vertices];
    make_initial_graph(vertices,graph);
    printf("please enter edges in the form (u  v)\n");

    for(iloop=0; iloop<edges; iloop++)
    {
        scanf("%d",&iindex);
        scanf("%d",&jindex);
        graph[iindex-1][jindex-1]=1;
        graph[jindex-1][iindex-1]=1;
    }

    // print_graph(vertices,graph);
    make_initial_arra(arr,vertices);

    printf("please enter starting vertex:");
    scanf("%d",&scan);

    float k=0.9;
    int q=0;

    while(((q - k) != 1)|| k<1)
    {
        printf("please enter value k:");
        scanf("%f",&k);
        q=(int)k;
        ++q;
        if((q - k) != 1|| k<1)
            printf("\nPlease enter an integer bigger than 0\n\n");
    }


    arr[scan-1]=0;


    printf("\nThere are %d people with %d connections away starting from %d\n", put_neighbour(vertices,graph,arr,scan,(int)k),(int)k,scan);

    // display_our_array(arr,vertices);

}


int main()
{
    printf("Hello world!\n");
    Q1();
    return 0;
}
