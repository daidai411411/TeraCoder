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
#include <stack>
#include <string>
#include <tuple>
#include <unordered_set>
#include <vector>

#define C(i) "Case #" << (i + 1) << ":\n"

using namespace std;
using ll = long long;

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    ll a, s = 0;
    for (int j = 0; j < n; j++) {
      cin >> a;
      s += a;
    }
    cout << C(i) << s << endl;
  }

  return 0;
}