/*বিসমিল্লাহির রাহমানির রাহীম*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 5;

int mx = 0, node = 1;
vector<int> dis1(N);
vector<int> dis2(N);
vector<int> dis(N);
vector<int> g[N];
void dfs(int s, int p, vector<int> &dis) {
  for(int v : g[s]) {
    if(v != p) {
      dis[v] = dis[s] + 1;
      if(dis[v] >= mx) {
        mx = dis[v];
        node = v;
      }
      dfs(v, s, dis);
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
  dfs(1, 0, dis);
  dfs(node, 0, dis2);
  dfs(node, 0, dis1);
  for(int i = 1; i <= n; i++) {
    cout << max(dis1[i], dis2[i]) << " ";
  }
}

int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 1, c = 1;
  //cin >> t;
  while(t--) {
    solve();
  }
}
