#include <stdio.h>

#define MAX 100000

void merge_sort(double nums[], int s, int e);
void merge(double nums[], int s, int m, int e);

int main() {
    int n = 0, i;
    double nums[MAX], num;

    printf("Digite numeros nao negativos (digite um negativo para parar)\n");
    do {
        printf("%do. numero: ", n+1);
        scanf("%lf", &num);
        if (num >= 0) {
            nums[n] = num;
            n++;
        }
    } while (num >= 0);

    merge_sort(nums, 0, n-1);

    printf("Numeros em ordem crescente:\n");
    for (i = 0; i < n; i++) {
        printf("%lf\n", nums[i]);
    }

    return 0;
}

void merge_sort(double nums[], int s, int e) {
    int m = (s + e) / 2;

    if (s >= e) return;
    
    merge_sort(nums, s, m);
    merge_sort(nums, m+1, e);

    merge(nums, s, m, e);
}

void merge(double nums[], int s, int m, int e) {
    int i, j, k;
    int n1 = m - s + 1, n2 = e - m;
    double numsL[MAX/2], numsR[MAX/2];

    for (i = 0; i < n1; i++) 
        numsL[i] = nums[s + i];

    for (i = 0; i < n2; i++)
        numsR[i] = nums[m + 1 + i];

    i = 0;
    j = 0;
    k = s;
    while (i < n1 && j < n2) {
        if (numsL[i] <= numsR[j]) {
            nums[k] = numsL[i];
            i++;
        } else {
            nums[k] = numsR[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        nums[k] = numsL[i];
        i++;
        k++;
    }
    while (j < n2) {
        nums[k] = numsR[j];
        j++;
        k++;
    }
}