#include <stdio.h>

void Insetion_Sort(int arr[],int n)
{
    int j,key;
    for(int i=1;i<n;i++)
    {
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key)  
        {
            arr[j+1]=arr[j];    
            j=j-1;            
        }
        arr[j+1]=key;
    }

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
    Insetion_Sort(arr,n);
    printf("After Sorting : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
