#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf 1000000007
const int N = 2e5 + 5;
void initialization(vector<int> &Parent, vector<int> &Rank, int n, vector<int> &si)
{
  for(int i = 0; i < n; i++)
  {
    Parent[i] = i;
    Rank[i] = 0;
    si[i] = 1;
  }
}
int findParent(vector<int> &Parent, int node)
{
  if(Parent[node] == node) return node;
  return Parent[node] = findParent(Parent, Parent[node]);
}
void unionSet(int u, int v, vector<int> &Parent, vector<int> &Rank, vector<int> &si)
{
  u = findParent(Parent, u);
  v = findParent(Parent, v);
  if(Rank[u] < Rank[v])
  {
    Parent[u] = v;
    si[v] += si[u];
  }
  else if(Rank[v] < Rank[u])
  {
    Parent[v] = u;
    si[u] += si[v];
  }
  else
  {
    Parent[v] = u;
    si[u] += si[v];
    Rank[u]++;
  }
}
void solve(int tes)
{
//cout << "node = 0, 1, 2, ... n - 1 porjonto";
  int n;
  cin >> n;
  vector<int> Parent(n);
  vector<int> Rank(n);
  vector<int> si(n);
  initialization(Parent, Rank, n, si);
  int q;
  cin >> q;
  int extra_edge = 0;
  while(q--)
  {
    int u, v; cin >> u >> v;
    u--,v--;
    if(findParent(Parent, u) == findParent(Parent, v)) {
      extra_edge++;
    }
    else {
      unionSet(u, v, Parent, Rank, si);
    }
    vector<int> a;
    for(int i = 0; i < n; i++) {
      if(findParent(Parent, i) == i) {
        a.push_back(si[i]);
      }
    }
    sort(a.rbegin(), a.rend());
    int ans = a[0];
    int N = a.size();
    for(int i = 1; i <= min(N, extra_edge); i++) {
      ans += a[i];
    }
    cout << ans - 1 << endl;
  }
}
int32_t main()
{
  ios::sync_with_stdio(0), cin.tie(0),cout.tie(0);
  int t = 1, c = 1;
//cin >> t;
  while(t--)
  {
    solve(c++);
  }
}
