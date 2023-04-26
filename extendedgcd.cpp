/*বিসমিল্লাহির রাহমানির রাহীম*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 5;

pair<int, int> extended_gcd(int a, int b) {
  if(b == 0) {
    return {1, 1};
  }
  auto [x2, y2] = extended_gcd(b, a % b);
  int x = y2;
  int y = x2 - (a / b) * y2;
  return {x ,y};
}

void solve() {
  pair<int, int> p = extended_gcd(55, 80);
  cout << p.first << " " <<p.second;
}

int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 1, c = 1;
  //cin >> t;
  while(t--) {
    solve();
  }
}

