#include <bits/stdc++.h>
using namespace std;

int maxIsolation(const string& expertise, const string& workspace) {
    int k = expertise.size();
    int n = workspace.size();
    
    vector<int> left(k), right(k);
    
    // Left[i] = earliest position where we can place engineer i
    int j = 0;
    for (int i = 0; i < k; i++) {
        while (j < n && workspace[j] != expertise[i]) j++;
        left[i] = j++;
    }
    
    // Right[i] = latest position where we can place engineer i
    j = n - 1;
    for (int i = k - 1; i >= 0; i--) {
        while (j >= 0 && workspace[j] != expertise[i]) j--;
        right[i] = j--;
    }
    
    // Binary search on the isolation value
    int lo = 0, hi = n;
    int ans = 0;
    
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        
        // Check if we can achieve isolation of at least mid
        vector<int> pos(k);
        pos[0] = left[0];
        bool valid = true;
        
        for (int i = 1; i < k; i++) {
            // Engineer i must be placed at least (pos[i-1] + mid + 1) positions away
            int minPos = pos[i - 1] + mid + 1;
            
            // Find the earliest valid position >= minPos with correct expertise
            int nextPos = -1;
            for (int p = minPos; p <= right[i]; p++) {
                if (workspace[p] == expertise[i]) {
                    nextPos = p;
                    break;
                }
            }
            
            if (nextPos == -1) {
                valid = false;
                break;
            }
            pos[i] = nextPos;
        }
        
        if (valid) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    
    return ans;
}

int main() {
    cout << maxIsolation("abcba", "abcbabcba") << endl;     // Expected 4
    cout << maxIsolation("abcdef", "azzabycdef") << endl;   // Expected 3
    cout << maxIsolation("bab", "babcab") << endl;          // Expected 3
    
    return 0;
}