#include <stdio.h>
int main()
{
    int arr[100];
    int n;
    int num, pos;
    printf("enter number of elements : ");
    scanf("%d", &n);

    printf("\nenter %d elements for array : ", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("enter position of inserting : ");
    scanf("%d", &pos);
    printf("enter element to insert : ");
    scanf("%d", &num);

    for (int i = n - 1; i >= pos; i++)
    {
        arr[i + 1] = arr[i];
    }
    arr[pos] = num;
    printf("checkpoint 1\n");

    n++;
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}