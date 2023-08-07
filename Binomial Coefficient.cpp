#include <stdio.h>
unsigned long long binomialCoefficient(int n, int r) {
    unsigned long long dp[n + 1][r + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= r && j <= i; j++) {
            if (j == 0 || j == i)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
    return dp[n][r];
}
int main() {
    int n, r;
    printf("Enter the value of n : ");
    scanf("%d", &n);
    printf("Enter the value of r : ");
    scanf("%d", &r);
    unsigned long long result = binomialCoefficient(n, r);
    printf("Binomial Coefficient C(%d, %d) = %llu\n", n, r, result);
    return 0;
}
