/*বিসমিল্লাহির রাহমানির রাহীম*/
#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e6 + 5;
const int p1 = 137, mod1 = 1e9 + 7, p2 = 277, mod2 = 1e9 + 9;

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

int ip1, ip2;
pair<int, int> pw[N], ipw[N];
//ipw to claculate (1 / x);

void prec() {
    pw[0] = {1, 1};
    for(int i = 1; i < N; i++) {
        pw[i].first = pw[i - 1].first * p1 % mod1;
        pw[i].second = pw[i - 1].second * p2 % mod2;
    }
    //1 / p1
    ip1 = bigmod(p1, mod1 - 2, mod1);
    ip2 = bigmod(p2, mod2 - 2, mod2);
    ipw[0] = {1, 1};
    for(int i = 1; i < N; i++) {
        ipw[i].first = ipw[i - 1].first * ip1 % mod1;
        ipw[i].second = ipw[i - 1].second * ip2 % mod2;
    }
}

pair<int, int> string_hash(string s) {
    int n = s.size();
    pair<int, int> hs({0, 0});
    for(int i = 0; i < n; i++) {
        hs.first += s[i] * pw[i].first % mod1;
        hs.first %= mod1;
        hs.second += s[i] * pw[i].second % mod2;
        hs.second %= mod2;
    }
    return hs;
}

pair<int, int> pref[N];
void build(string s) {
    int n = s.size();
    for(int i = 0; i < n; i++) {
        pref[i].first = s[i] * pw[i].first % mod1;
        if(i) pref[i].first = (pref[i].first + pref[i - 1].first) % mod1;
        pref[i].second = s[i] * pw[i].second % mod2;
        if(i) pref[i].second = (pref[i].second + pref[i - 1].second) % mod2;
    }
}

pair<int, int> get_hash(int i, int j) {
    assert(i <= j);
    pair<int, int> hs({0, 0});
    hs.first = pref[j].first;
    if(i) hs.first = (hs.first - pref[i - 1].first + mod1) % mod1;
    hs.first = hs.first * ipw[i].first % mod1;
    hs.second = pref[j].second;
    if(i) hs.second = (hs.second - pref[i - 1].second + mod2) % mod2;
    hs.second = hs.second * ipw[i].second % mod2;
    return hs;
}

void solve() {
    prec();
  string a, b; cin >> a >> b;
  build(a);
  int ans = 0, n = a.size(), m = b.size();
  //cout << (get_hash(0, 1) == get_hash(3, 4)) << endl;
  auto hash_b = string_hash(b);
  for(int i = 0; i + m - 1 < n; i++) {
      ans += get_hash(i, i + m - 1) == hash_b;
  }
  //number of substring
  cout << ans << endl;
}

int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 1, c = 1;
  //cin >> t;
  while(t--) {
    solve();
  }
}

