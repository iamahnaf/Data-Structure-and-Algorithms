#include <bits/stdc++.h>
using namespace std;
//https://tin.al/ahnafdsa
// -------------------- FAST I/O --------------------
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);

// -------------------- TYPE SHORTCUTS --------------------
using ll  = long long;
using ull = unsigned long long;
using ld  = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi  = vector<int>;
using vll = vector<ll>;

// -------------------- CONSTANTS --------------------
const int INF  = 1e9;         // "infinity" for int
const ll LINF  = 1e18;        // "infinity" for long long
const int MOD  = 1e9+7;       // default mod (prime)
const int MOD2 = 998244353;   // another common mod
const int N    = 2e5+5;       // adjust for problem limits

// -------------------- GCD & LCM --------------------
ll gcdll(ll a, ll b) { return b ? gcdll(b, a % b) : a; }
ll lcmll(ll a, ll b) { return a / gcdll(a,b) * b; }

// -------------------- MODULAR ARITHMETIC --------------------
ll modpow(ll a, ll b, ll m = MOD) {
    ll res = 1; a %= m;
    while(b > 0) {
        if(b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll modinv(ll a, ll m = MOD) {
    // only works if m is prime
    return modpow(a, m-2, m);
}

// -------------------- SIEVE OF ERATOSTHENES --------------------
vector<int> primes;
vector<bool> isPrime;
void sieve(int n) {
    isPrime.assign(n+1, true);
    isPrime[0] = isPrime[1] = false;
    for(int i=2; i*i<=n; i++) {
        if(isPrime[i]) {
            for(int j=i*i; j<=n; j+=i) isPrime[j] = false;
        }
    }
    for(int i=2; i<=n; i++) if(isPrime[i]) primes.push_back(i);
}

// -------------------- MAIN SOLVER --------------------
void solve() {
    // your problem solution here
    int n; cin >> n;
    cout << "You entered: " << n << "\n";
}

int main() {
    FAST_IO;
    int t = 1;
    //cin >> t; // uncomment for multiple test cases
    
   // while(t--) solve();
}
