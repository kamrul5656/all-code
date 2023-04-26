/*বিসমিল্লাহির রাহমানির রাহীম*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;

vector<int> g[N];
int mx, node, ans;
int dep[N];

void dfs1(int u, int p) {
  dep[u] = dep[p] + 1;
  if(dep[u] > mx) {
    mx = dep[u];
    node = u;
  }
  for(int v : g[u]) {
    if(v != p) {
      dfs1(v, u);
    }
  }
}

void dfs2(int u, int p) {
  dep[u] = dep[p] + 1;
  ans = max(ans, dep[u] - 1);
  for(int v : g[u]) {
    if(v != p) {
      dfs2(v, u);
    }
  }
}

void dfs3(int u, int p, vector<int> &d) {
  dep[u] = dep[p] + 1;
  d[u] = dep[u] - 1;
  for(int v : g[u]) {
    if(v != p) {
      dfs3(v, u, d);
    }
  }
}


void solve() {
  int n; cin >> n;
  for(int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs1(1, 0);
  dfs2(node, 0);
  vector<int> d1(n + 1), d2(n + 2);
  dfs3(node, 0, d1);
  dfs1(node, 0);
  dfs3(node, 0, d2);
  for(int i = 1; i <= n; i++) cout << d1[i] << " ";
  cout << endl;
  for(int i = 1; i <= n; i++) cout << d2[i] << " ";
  cout << endl;
}

int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 1, c = 1;
  //cin >> t;
  while(t--) {
    solve();
  }
}

