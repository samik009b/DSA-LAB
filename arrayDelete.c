#include <stdio.h>
int main()
{
    int arr[100];
    int n;
    int pos;
    printf("enter number of elements : ");
    scanf("%d", &n);

    printf("\nenter %d elements for array : ", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("enter position of element to delete : ");
    scanf("%d", &pos);

    for (int i = pos; i < n; i++)
    {
        arr[i] = arr[i + 1];
    }
    printf("new array : ");

    for (int i = 0; i < n - 1; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
