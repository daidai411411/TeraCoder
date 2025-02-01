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
  int n, m, o;
  cin >> n;
  vector<int> p(n);
  for (int& i : p) cin >> i;

  ll sum_m = 0, sum_o = 0;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int s;
    cin >> s;
    sum_m += p[s - 1];
  }
  cin >> o;
  for (int i = 0; i < o; i++) {
    int l;
    cin >> l;
    sum_o += p[l - 1];
  }

  cout << sum_m << ' ' << sum_o << ' ' << (sum_m + sum_o) << endl;
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