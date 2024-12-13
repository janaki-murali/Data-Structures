#include <stdio.h>

void QuickSort(int arr[],int low,int high)
{
    int pivot,i,j,temp;
    if(low >= high)
    {
        return;
    }
    pivot=arr[low];
    i=low+1;
    j=high;
    while(i<=j)
    {
        while(arr[i] < pivot)
        {
            i++;
        }
        while(arr[j] > pivot)
        {
            j--;
        }
        if(i<j)
        {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    temp=arr[j];
    arr[j]=pivot;
    arr[low]=temp;
    QuickSort(arr,low,j-1); 
    QuickSort(arr,j+1,high);    
}

void main()
{
    int n,arr[25];
    printf("Number of elements in the array : ");
    scanf("%d",&n);
    printf("Enter the elements : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    QuickSort(arr,0,n-1);
    printf("After Sorting : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
