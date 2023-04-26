/*বিসমিল্লাহির রাহমানির রাহীম*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 5;

int ar[N], tree[N];
int n;

int query(int idx) {
  int sum = 0;
  while(idx > 0) {
    sum += tree[idx];
    idx -= (idx & -idx);
  }
  return sum;
}

void update(int idx, int val) {
  while(idx <= n) {
    tree[idx] += val;
    idx += (idx & -idx);
  }
}

void solve() {
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> ar[i];
    update(i, ar[i]);
  }
  cout << query(3) << endl;
  update(3, 5);
  cout << query(3);
}

int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 1, c = 1;
  //cin >> t;
  while(t--) {
    solve();
  }
}

