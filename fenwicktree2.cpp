/*বিসমিল্লাহির রাহমানির রাহীম*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 5;

int BIT[N], a[N], n;

void update(int x, int delta) {
  for(; x <= n; x += x&-x) {
    BIT[x] += delta;
  }
}

int query(int x) {
  int sum = 0;
  for(; x > 0; x -= x&-x) {
    sum += BIT[x];
  }
  return sum;
}

int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    update(i, a[i]);
  }
  cout << query(3);
  return 0;
}

