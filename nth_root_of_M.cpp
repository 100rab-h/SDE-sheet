double multiply(double mid, int n) {
    double ans = 1.0;
    for (int i = 0; i < n; i++) {
        ans *= mid;
    }
    return ans;
}
double findNthRootOfM(int n, int m) {
	// Write your code here.
    double low = low = 1;
    double high = m;
    double eps = 1e-8;
    
    while ((high - low) > eps) {
        double mid = (low + high) / 2.0;
        if (multiply(mid, n) < m) low = mid;
        else high = mid;
    }
    
    
    return high;
}
