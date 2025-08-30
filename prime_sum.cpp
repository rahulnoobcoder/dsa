#include <bits/stdc++.h>
using namespace std;
#include <climits>

bool isPrime(long long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;

    if (n % 2 == 0 || n % 3 == 0) return false;

    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) 
            return false;
    }
    return true;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long n;
    cin >> n;
    cout << LLONG_MAX << endl;  // prints 9223372036854775807

    if (isPrime(n)) cout << n << " is Prime\n";
    else cout << n << " is Not Prime\n";

    return 0;
}
