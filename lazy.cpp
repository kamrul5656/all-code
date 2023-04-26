/*বিসমিল্লাহির রাহমানির রাহীম*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 5;
int tree[4 * N];
int arr[N + 5];
int lazy[4 * N + 5];

void build(int node, int start, int end) {
  lazy[node] = 0;
  if(start == end) {
    tree[node] = arr[start];
    return;
  }
  int mid = (start + end) / 2;
  build(2 * node, start, mid);
  build(2 * node + 1, mid + 1, end);
  tree[node] = tree[2 * node] + tree[2 * node + 1];
}

void push(int node, int st, int en) {
  if(lazy[node] == 0) return;
  tree[node] += (lazy[node] * (en - st + 1));
  if(st != en) {
    lazy[2 * node] += lazy[node];
    lazy[2 * node + 1] += lazy[node];
  }
  lazy[node] = 0;
}

void update(int node, int st, int en, int i, int j, int val) {
  push(node, st, en);
  if(st > j or en < i) return;
  if(st >= i and en <= j) {
    lazy[node] = val;
    push(node, st, en);//must
    return;
  }
  int mid = (st + en) / 2;
  update(2 * node, st, mid, i, j, val);
  update(2 * node + 1, mid + 1, en, i, j, val);
  tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int query(int node, int st, int en, int i, int j) {
  push(node, st, en);
  if(st > j or en < i) return 0;
  if(st >= i and en <= j) return tree[node];
  int mid = (st + en) / 2;
  return query(2 * node, st, mid, i, j) + query(2 * node + 1, mid + 1, en, i, j);
}

void solve() {
  int n;
  cin >> n;
  int q;
  cin >> q;
  for(int i = 1; i <= n; i++) arr[i] = 0;
  build(1, 1, n);
  while(q--) {

  }
}

int32_t main() {

  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int t = 1;
  //cin >> t;
  while(t--) {
    solve();
  }
}
