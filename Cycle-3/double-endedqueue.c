/*To implement DOUBLE ENDED QUEUE using array*/

#include <stdio.h>
#define size 25

int dq[size],front=-1,rear=-1;
void InsertFront(int item)
{
    int i;
    if(front==0 && rear==size-1)
    {
        printf("Dequeu Full\n");
    }
    else if(rear==-1)
    {
        front=0;
        rear=0;
        dq[front]=item;
    }
    else if(front>0)
    {
        front--;
        dq[front]=item;
    }
    else
    {
        for(i=rear;i>=front;i--)
        {
            dq[i+1]=dq[i];
        }
        dq[front]=item;
        rear++;
    }
}
void InsertRear(int item)
{
    int i;
    if(front==0 && rear==size-1)
    {
        printf("Dequeu Full\n");
    }
    else if(rear==-1)
    {
        rear=0;
        front=0;
        dq[rear]=item;
    }
    else if(rear<size-1)
    {
        rear++;
        dq[rear]=item;
    }
    else
    {
        for(i=front;i<=rear;i++)
        {
            dq[i-1]=dq[i];
        }
        dq[rear]=item;
        front--;
    }
}
void DeleteFront()
{
    if(front==-1)
    {
        printf("DeQueue Empty\n");
    }
    else if(front==rear)
    {
        printf("Element deleted : %d\n",dq[front]);
        front=-1;
        rear=-1;
    }
    else
    {
        printf("Element deleted : %d\n",dq[front]);
        front++;
    }
}
void DeleteRear()
{
    if(front==-1)
    {
        printf("DeQueue Empty\n");
    }
    else if(front==rear)
    {
        printf("Element deleted : %d\n",dq[front]);
        front=-1;
        rear=-1;
    }
    else
    {
        printf("Element deleted : %d\n",dq[rear]);
        rear--;
    }
}
void display()
{
    int i;
    if(front==-1)
    {
        printf("DeQueue Empty\n");
    }
    else
    {
        printf("Elements in Dequeue : ");
        for(i=front;i<=rear;i++)
        {
            printf("%d ",dq[i]);
        }
        printf("\n");
    }
}

void main()
{
    int value,item;
    char ch='y';
    while (ch=='y'||ch=='Y')
    {
        printf("1 : ENQUEUE through Front\n2 : ENQUEUE through Rear\n3 : DEQUEUE through Front\n4 : DEQUEUE through Rear\n5 : DISPLAY\n");
        printf("Enter your choice : ");
        scanf("%d",&value);
        switch(value)
        {
            case 1: printf("Enter the element to be inserted : ");
                    scanf("%d",&item);
                    InsertFront(item);
                    break;
            case 2: printf("Enter the element to be inserted : ");
                    scanf("%d",&item);
                    InsertRear(item);
                    break;
            case 3: DeleteFront();
                    break;
            case 4: DeleteRear();
                    break;
            case 5: display();
                    break;
            default : printf("Invalid Choice!!\n");
        }
        printf("Do you want to continue ?(y/n) : ");
        scanf(" %c",&ch);
    }
}
