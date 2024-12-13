#include <stdio.h>

int A[100],I=1,S[100],top=-1,l;

void push(int X)
{
    top++;
    S[top]=X;
}

int pop()
{
    int X;
    if(top==-1)
    {
        return -9999;
    }
    X=S[top];
    top--;
    return X;
}

void inorder(int I)
{
    int data;
    if(A[I]!=0)
    {
        push(A[I]);
        inorder(2*I);
    
        while(top!=-1)
        {
            data=pop();
            if (data!=-9999)
            {
                printf("%d ",data);
            }
        }
        //printf("%d ",A[I]);
        inorder(2*I+1);
    }
}

void preorder(int I)
{
    int data;
    if(A[I]!=0)
    {
        printf("%d ",A[I]);
        preorder(2*I);
    
        while(top!=-1)
        {
            data=pop();
            if (data!=-9999)
            {
                printf("%d ",data);
            }
        }
        preorder(2*I+1);
    }
}

void postorder(int I)
{
    int data;
    if(A[I]!=0)
    {
        postorder(2*I);
    
        while(top!=-1)
        {
            data=pop();
            if (data!=-9999)
            {
                printf("%d ",data);
            }
        }
        postorder(2*I+1);
        printf("%d ",A[I]);
    }
}

void BuildTree(int data,int I)
{
    int value;
    char ch;
    l=I;
    A[I]=data;
    printf("Node with data %d has left node ?(y/n) : ",data);
    scanf(" %c",&ch);
    if (ch=='y' || ch=='Y')
    {
        printf("Enter the data : ");
        scanf("%d",&value);
        l=2*I;
        BuildTree(value,2*I);
    }
    printf("Node with data %d has right node ?(y/n) : ",data);
    scanf(" %c",&ch);
    if (ch=='y' || ch=='Y')
    {
        printf("Enter the data : ");
        scanf("%d",&value);
        l=2*I+1;
        BuildTree(value,2*I+1);
    }
}
