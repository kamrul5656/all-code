/*বিসমিল্লাহির রাহমানির রাহীম*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;

const int mod = 1e9 + 7;

int power(int n, int k) {
  int ans = 1; n = n % mod;
  if(n < 0) n += mod;
  while(k) {
    if(k & 1) ans = ans * n % mod;
    n = n * n % mod;
    k >>= 1;
  }
  return ans;
}

int f[N], invf[N];
int nCr(int n, int r) {
  if(n < r or n < 0) return 0;
  return f[n] * invf[r] % mod * invf[n - r] % mod;
}

int nPr(int n, int r) {
  if(n < r or n < 0) return 0;
  return f[n] * invf[n - r] % mod;
}

void solve() {
  f[0] = 1;
  for(int i = 1; i < N; i++) {
    f[i] = i * f[i - 1] % mod;
  }
  invf[N - 1] = power(f[N - 1], mod - 2);
  for(int i = N - 2; i >= 0; i--) {
    invf[i] = invf[i + 1] * (i + 1) % mod;
  }
  cout << nCr(6, 2) << endl;
  cout << nPr(6, 2) << endl;
}

int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 1, c = 1;
  //cin >> t;
  while(t--) {
    solve();
  }
}

