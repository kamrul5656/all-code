/*বিসমিল্লাহির রাহমানির রাহীম*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 1000000

int tree[4 * N + 5];
int arry[N + 1];
int n;

void build(int node, int start, int end) {
    if(start == end) {
        tree[node] = arry[start];
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int query(int node, int start, int end, int left, int right) {
    if(start > right or end < left) return 0;
    if(start >= left and end <= right) return tree[node];
    int mid = (start + end) / 2;
    return query(2 * node, start, mid, left, right) + query(2 * node + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int in, int val) {
    if(start > in or end < in) return;
    if(start == in and end == in) {
        tree[node] = val;
        return;
    }
    int mid = (start + end) / 2;
    update(2 * node, start, mid, in, val);
    update(2 * node + 1, mid + 1, end, in, val);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

void solve() {
    int q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> arry[i];
    build(1, 1, n);
    while(q--) {

    }
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1, c = 1;
    //cin >> t
    while(t--) {
        solve();
    }
}
