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

void Dfs() {

}

void Solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adjs(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adjs[a].push_back(b);
  }

  set<int> in_cycle;

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