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

ll SymbolToNumber(char s) {
  if ('0' <= s and s <= '9') return (s - '0');
  else if ('A' <= s and s <= 'Z') return (s - 'A' + 10);
  else return (s - 'a' + 36);
}

char NumberToSymbol(ll n) {
  if (0 <= n and n <= 9) return (n + '0');
  else if (10 <= n and n <= 35) return (n - 10 + 'A');
  else return (n - 36 + 'a');
}

ll NToDec(ll n, string s) {
  ll d = 0;
  for (ll i = 0, w = 1; i < s.size(); i++, w *= n) {
    ll digit = SymbolToNumber(s[s.size() - 1 - i]);
    d += digit * w;
  }
  return d;
}

string DecToM(ll m, ll d) {
  if (d == 0) return "0";
  string s;
  while (d != 0) {
    char digit = NumberToSymbol(d % m);
    s = digit + s;
    d /= m;
  }
  return s;
}

void Solve() {
  ll n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  string ans = DecToM(m, NToDec(n, s));
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
