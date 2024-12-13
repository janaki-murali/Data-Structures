#include <stdio.h>
void main()
{
    int n,i,key,a[10],present=0;
    printf("How many elements ? : ");
    scanf("%d",&n);
    printf("Enter the elements : ");
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the number to be searched : ");
    scanf("%d",&key);
    for (i=0;i<n;i++)
    {
        if (key==a[i])
        {
            printf("%d is PRESENT at location %d\n",key,i+1);
            present=1;
            break;
        }
    }
    if (!present)
    {
        printf("%d NOT PRESENT\n",key);
    }
}
