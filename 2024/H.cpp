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

ll SumOfCubes(ll n) {
  ll triangular_num = (n * (n + 1) / 2) % M;
  return (triangular_num * triangular_num) % M;
}

void Solve() {
  ll a, n;
  cin >> a >> n;

  ll ans = (SumOfCubes(n) - SumOfCubes(a - 1) + M) % M;
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

/*


t^2 % M = (Mq+r)^2 % M = r^2 % M

*/