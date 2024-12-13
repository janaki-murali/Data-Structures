/*To find the smallest number in a list using pointers*/

#include <stdio.h>
void main()
{
    int a[20],n,i,*small;
    small=a;
    printf("Numbers in the list : ");
    scanf("%d",&n);
    printf("Enter the numbers : ");
    for (i=0;i<n;i++)
        scanf("%d",&a[i]);
    for (i=0;i<n;i++)
    {
        if (*(a+i) < *small)
            small=(a+i);
    }
    printf("Smallest Number : %d\n",*small);
}
