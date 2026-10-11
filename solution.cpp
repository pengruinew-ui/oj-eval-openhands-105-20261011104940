#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdio>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    // E[k] = expected days to eat m apples when we have k apples
    vector<double> E(n + 1, 0.0);
    
    // Base case: E[0] = 0 (no apples left, no more days needed)
    E[0] = 0.0;
    
    // Calculate E[k] for k from 1 to n
    for (int k = 1; k <= n; k++) {
        double sum = 0.0;
        // Sum E[k-i] for i from 1 to min(k, m-1)
        int max_i = min(k, m - 1);
        for (int i = 1; i <= max_i; i++) {
            sum += E[k - i];
        }
        // E[k] = 1 + (1/k) * sum
        E[k] = 1.0 + sum / k;
    }
    
    // Output with 2 decimal places
    cout << fixed << setprecision(2) << E[n] << endl;
    
    return 0;
}