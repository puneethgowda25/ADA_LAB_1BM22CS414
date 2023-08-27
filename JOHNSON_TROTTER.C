#include <stdio.h>
#include <stdbool.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int factorial(int n) {
    int res = 1;
    for (int i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}

void generatePermutations(int n) {
    int a[n], dir[n];
    
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
        dir[i] = -1;  // Initialize directions
        printf("%d ", a[i]);
    }
    printf("\n");
    
    for (int count = 1; count < factorial(n); count++) {
        int mobile = -1, mobileIdx = -1;
        
        for (int i = 0; i < n; i++) {
            if ((dir[i] == -1 && i > 0 && a[i] > a[i - 1]) ||
                (dir[i] == 1 && i < n - 1 && a[i] > a[i + 1])) {
                if (mobile == -1 || a[i] > a[mobileIdx]) {
                    mobile = a[i];
                    mobileIdx = i;
                }
            }
        }
        
        if (dir[mobileIdx] == -1) {
            swap(&a[mobileIdx], &a[mobileIdx - 1]);
        } else if (dir[mobileIdx] == 1) {
            swap(&a[mobileIdx], &a[mobileIdx + 1]);
        }
        
        for (int i = 0; i < n; i++) {
            if (a[i] > mobile) {
                dir[i] *= -1;
            }
        }
        
        for (int i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    generatePermutations(n);

    return 0;
}
