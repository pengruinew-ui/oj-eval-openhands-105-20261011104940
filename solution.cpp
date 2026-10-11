#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<double> E(n + 1, 0.0);
    E[0] = 0.0;
    
    for (int k = 1; k <= n; k++) {
        double sum = 0.0;
        int max_i = min(k, m - 1);
        for (int i = 1; i <= max_i; i++) {
            sum += E[k - i];
        }
        E[k] = 1.0 + sum / k;
    }
    
    cout << fixed << setprecision(2) << E[n] << endl;
    return 0;
}