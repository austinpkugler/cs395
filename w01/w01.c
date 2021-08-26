#include <stdio.h>
#include <stdlib.h>

int MinDistance(int size, int arr[]);

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Enter at least two elements.\n");
    }

    int arr[argc - 1];

    for (int i = 1; i < argc; ++i)
    {
        arr[i - 1] = atoi(argv[i]);
    }

    int dmin = MinDistance(argc - 1, arr);
    printf("Minimum distance: %d\n", dmin);

    return 0;
}

int MinDistance(int size, int arr[])
{
    int dmin = -1;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            int diff = abs(arr[i] - arr[j]);
            if ((i != j && diff < dmin) || dmin == -1)
            {
                dmin = diff;
            }
        }
    }
    return dmin;
}
