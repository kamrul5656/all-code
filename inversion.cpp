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


// int BIT[N + 1], a[N + 1], n;

// void update(int x, int delta) {
//   for(; x <= N; x += x&-x) {
//     BIT[x] += delta;
//   }
// }

// int query(int x) {
//   int sum = 0;
//   for(; x > 0; x -= x&-x) {
//     sum += BIT[x];
//   }
//   return sum;
// }


void solve() {
  cin >> n;
  int inversion = 0;
  //luv video
  for(int i = 1; i <= n; i++) {
    cin >> ar[i];
    inversion += query(N) - query(ar[i]);
    update(ar[i], 1);
  }
  cout << "ans = ";
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

