#include <stdio.h>
int arr[20];
int size;

int binarySearch(int target)
{
    int left = 0, right = size - 1;

    while (right >= left)
    {
        int mid = (right + left) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }

        else if (arr[mid] > target)
        {
            right = mid - 1;
        }

        else
        {
            left = mid + 1;
        }
    }
    return -1;
}
int main()
{
    int target;

    printf("enter the size of the array : ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("enter your target : ");
    scanf("%d", &target);

    int pos = binarySearch(target);
    if (pos == -1)
    {
        printf("the target has not been found");
    }
    else
        printf("the target %d is in position %d", arr[pos], pos);

    return 0;
}
