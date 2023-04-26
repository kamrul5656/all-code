/*বিসমিল্লাহির রাহমানির রাহীম*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 5;

int bigmod(int n, int k, int mod) {
    int ans = 1;
    n = n % mod;
    if(n < 0) n += mod;
    while(k) {
        //if k is odd
        if(k & 1LL) ans = ans * n % mod;
        n = n * n % mod;
        //k = k / 2
        k = k >> 1LL;
    }
    return ans;
}

void solve() {
    cout << bigmod(2, 5, 13) << endl;
}

int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 1, c = 1;
  //cin >> t;
  while(t--) {
    solve();
  }
}

