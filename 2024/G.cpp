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

void Solve() {
  ll n, m, k, d1, d2;
  cin >> n >> m >> k >> d1 >> d2;

  ll p1 = n, p2 = m;
  while (p1 != p2) {
    if (p1 < p2) p1 += d1;
    else p2 += d2;
  }
  ll l = lcm(d1, d2);
  ll p1_destroy = p1 + l * (k - 1);
  ll ans = (p1_destroy - n) / d1 + 1;
  cout << ans << endl;
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