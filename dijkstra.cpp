/*বিসমিল্লাহির রাহমানির রাহীম*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5, mod = 1e9 + 7;

vector<pair<int, int>> g[N];
int n, m;
const int inf = 1e17 + 7;


void solve() {
  cin >> n >> m;
  vector<int> dist(N, inf);

  for(int i = 0; i < m; i++) {
    int u, v, cost; cin >> u >> v >> cost;
    g[u].push_back({v, cost});
    //g[v].push_back({u, cost});
  }
  priority_queue<pair<int ,int>,vector<pair<int, int>>, greater<pair<int ,int>>> q;
  q.push({0, 1});
  vector<int> vis(N, 0);
  dist[1] = 0;
  while(!q.empty()) {
    auto a = q.top();
    q.pop();
    if(vis[a.second]) continue;
    vis[a.second] = 1;
    for(auto i : g[a.second]) {
      if(dist[a.second] + i.second < dist[i.first]) {
        dist[i.first] = dist[a.second] + i.second;
        q.push({dist[i.first], i.first});
      }
    }
  }
  for(int i = 1; i <= n; i++) {
    if(dist[i] < inf) {
      cout << dist[i] << " ";
    }
    else {
      cout << -1 << " ";
    }
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

