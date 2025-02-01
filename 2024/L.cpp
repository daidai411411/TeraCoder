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

bool IsPalindrome(string s) {
  int l = 0, r = s.size() - 1;
  while (l < r) {
    if (s[l] != s[r]) return false;
    l++;
    r--;
  }
  return true;
}

void Solve() {
  int n;
  cin >> n;
  vector<string> s(n);
  for (string& i : s) cin >> i;

  int point[2]{0, 0}, turn = 0;
  unordered_set<string> hist;
  for (int i = 0; i < n; i++) {
    bool connectable = (i == 0) or (s[i - 1].back() == s[i].front());
    bool used = hist.find(s[i]) != hist.end();
    if (!connectable or used) break;

    hist.insert(s[i]);
    if (IsPalindrome(s[i])) point[turn] += 2;
    else point[turn]++;
    turn = (turn + 1) % 2;
  }

  if (point[0] == point[1]) {
    cout << "draw\n"
         << -1 << endl;
  } else if (point[0] > point[1]) {
    cout << "Terako\n"
         << point[0] << endl;
  } else {
    cout << "TerakoA\n"
         << point[1] << endl;
  }
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