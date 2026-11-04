#include <stdio.h>
#include <stdlib.h>

int main() {
    int c = 0, k = 1;
    while (c < 1000) {
        if ( (k % 3 != 0) && (k % 7 != 0) ) {
            printf("%d ", k);
            c++;
        }
        k = k + 2;
    }
    return 0;
}
