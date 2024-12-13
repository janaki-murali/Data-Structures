/*To merge two arrays in ascending order and form a single array sorted in ascending order*/

#include <stdio.h>

void main()

{

    int a[20],b[20],c[20],i,j,k,l,n1,n2;

    printf("Enter the number of elements in first array : ");

    scanf("%d",&n1);

    printf("Enter the elements : \n");

    for (i=0;i<n1;i++)

        scanf("%d",&a[i]);

    printf("Enter the number of elements in second array : ");

    scanf("%d",&n2);

    printf("Enter the elements : \n");

    for (j=0;j<n2;j++)

        scanf("%d",&b[j]);

    i=0;j=0;

    while (i<n1 && j<n2)

    {

        if (a[i]<b[j])

        {

            c[k]=a[i];

            i++;

            k++;

        }

        else

        {

            c[k]=b[j];

            j++;

            k++;

        }

    }

    for (l=i;l<n1;l++)

    {

        c[k]=a[l];

        k++;

    }

    for (l=j;l<n2;l++)

    {

        c[k]=b[l];

        k++;

    }

    printf("After merge sort : ");

    for (i=0;i<k;i++)

        printf("%d ",c[i]);

    printf("\n");

}
