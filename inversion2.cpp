/*বিসমিল্লাহির রাহমানির রাহীম*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 5;

int ar[N + 1], tree[N + 1];
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
  //n er jaygay N hobe
  while(idx <= N) {
    tree[idx] += val;
    idx += (idx & -idx);
  }
}

void solve() {
  cin >> n;
  int inversion = 0;
  //luv video
  //if a[i] == 10^9 hoy then dimension reduction korte hobe
  //complexity = O(nlogn)
  //space complexity = O(n)
  map<int, int> mp;
  for(int i = 0; i < n; i++) {
    cin >> ar[i];
    mp[ar[i]] = 0;
  }
  int idx = 1;
  for(auto x : mp) {
    mp[x.first] = idx++;
  }
  vector<int> v;
  for(int i = 0; i < n; i++) {
    v.push_back(mp[ar[i]]);
  }
  for(int i = 0; i < n; i++) {
    inversion += query(N) - query(v[i]);
    update(v[i], 1);
  }
  cout << inversion << endl;
}

int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 1, c = 1;
  //cin >> t;
  while(t--) {
    solve();
  }
}

