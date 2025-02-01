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

#define M (998244353ll)

using namespace std;
using ll = long long;

ll tn(ll n) {
  return (n * (n + 1) / 2) % M;
}

void Solve() {
  ll n;
  cin >> n;

  ll s = 0;
  for (int j = 2; j < n; j++) {
    s += (j * tn(j - 1)) % M;
  }
  s = (s - tn(n - 2) + M) % M;

  cout << s << endl;
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

n=5

  j 1 2 3 4 5
i   - - - - -
1 | . f f f .
2 | . . f f .
3 | . . . f .
4 | . . . . .
5 | . . . . .

*/