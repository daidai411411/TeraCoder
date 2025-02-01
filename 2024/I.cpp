#include <algorithm>
#include <array>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_set>
#include <vector>

using namespace std;
using ll = long long;

bool ChMax(ll& a, ll b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

void Dfs(int n, const vector<vector<ll>>& p, vector<ll>& max_happiness, int hist, int count) {
  if (count == n) return;
  for (int i = 0; i < n; i++) {
    int b = 1 << i;
    if (hist & b) continue;
    if (ChMax(max_happiness[hist | b], max_happiness[hist] - p[i][count])) {
      Dfs(n, p, max_happiness, hist | b, count + 1);
    }
  }
}

void Solve() {
  int n;
  cin >> n;
  vector<vector<ll>> p(n, vector<ll>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) cin >> p[i][j];
  }

  vector<ll> max_happiness(1 << n, -(1ll<<32));
  max_happiness[0] = 1'000'000'000;
  Dfs(n, p, max_happiness, 0, 0);

  cout << max_happiness.back() << endl;
}

int main() {
  int t;
  cin >> t;
  cin.ignore();
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ":" << endl;
    Solve();
  }

  return 0;
}

/*

4
3
1 10 100
100 1 10
10 100 1
5
100000 100000 100000 1 100000
10 20 30 40 50
2 1 3 5 4
123 234 345 456 567
9999 7777 5555 3333 1111
1
10
3
1000000000 1000000000 1000000000
1000000000 1000000000 1000000000
1000000000 1000000000 1000000000

*/