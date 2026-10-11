#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    double E[25];
    E[0] = 0.0;
    
    for (int k = 1; k <= n; k++) {
        double sum = 0.0;
        int max_i = min(k, m - 1);
        for (int i = 1; i <= max_i; i++) {
            sum += E[k - i];
        }
        E[k] = 1.0 + sum / k;
    }
    
    printf("%.2f\n", E[n]);
    return 0;
}