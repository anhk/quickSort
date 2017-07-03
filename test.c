
#include <stdio.h>

#define swap(a,b) do { a ^= b; b ^= a; a ^= b; } while (0)

int split(int a[], int low, int high)
{
    int part_element = a[low];

    for (;;) {
        while (low < high && part_element <= a[high]) {
            high--;
        }
        if (low >= high) break;
        a[low++] = a[high];

        while (low < high && a[low] <= part_element) {
            low++;
        }
        if (low >= high) break;
        a[high--] = a[low];
    }

    a[high] = part_element;
    return high;
}

void quickSort(int a[], int low, int high)
{
    int middle;

    if (low >= high) return;
    middle = split(a, low, high);
    quickSort(a, low, (middle-1));
    quickSort(a, (middle+1), high);
}

int main(int argc, char **argv)
{
    int a[] = { 9, 3};
    //int a[] = { 9, 3, 2, 39, 1, 394,3, 194, 98};

    quickSort(a, 0, (sizeof(a) / sizeof(a[0])) - 1);

    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i ++) {
        printf(" %d ", a[i]);
    }
    printf("\n");

    return 0;
}
