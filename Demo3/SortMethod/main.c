#include <stdio.h>

void numberChange(int array[], int m, int n)
{
    int tmp = array[m];
    array[m] = array[n];
    array[n] = tmp;
}

void printfArray(int array[], int num)
{
    int m = 0;
    for (m = 0; m < num; m++)
    {
        printf("%d ", array[m]);
    }
    printf("\n");
}

void bubbleSort(int array[], int num)
{
    int n = num / sizeof(int);
    int i = 0;
    int j = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                numberChange(array, j, j + 1);
            }
        }
    }
    printfArray(array, n);
}

void cocktailSort(int array[], int num)
{
    int n = num / sizeof(int);
    int left = 0;
    int right = n - 1;

    int i = 0;
    int j = 0;

    while (left < right) {
        for (i = 0; i < right; i++) {
            if (array[i] > array[i + 1]) {
                numberChange(array, i, i+1);
            }
        }
        right--;

        for (j = right; j > 0; j--) {
            if (array[j] > array[j + 1]) {
                numberChange(array, i, i+1);
            }
        }
        left++;
    }
    printfArray(array, n);
}

int main(void)
{
    int array[] = {3, 1, 6, 3, 8, 9, 4, 2, 5, 8, 1, 0, 9, 2};
    bubbleSort(array, sizeof(array));

    cocktailSort(array, sizeof(array));

    return 0;
}

