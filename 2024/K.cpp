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

void GetPostorder(vector<int>& postorder, const vector<unordered_set<int>>& adjacents, int current, vector<bool>& visited) {
	visited[current] = true;
	for (int adjacent : adjacents[current]) {
		if (visited[adjacent]) continue;
		GetPostorder(postorder, adjacents, adjacent, visited);
	}
	postorder.push_back(current);
}

void GetScc(set<int>& scc, const vector<unordered_set<int>>& adjacents, int current, vector<bool>& visited) {
	visited[current] = true;
	for (int adjacent : adjacents[current]) {
		if (visited[adjacent]) continue;
		GetScc(scc, adjacents, adjacent, visited);
	}
	scc.insert(current);
}

set<set<int>> IntoSccSet(const int n, const vector<unordered_set<int>>& adjacents) {
	vector<int> postorder;
	vector<bool> visited(n, false);
	GetPostorder(postorder, adjacents, 0, visited);

	vector<unordered_set<int>> adjacents_t(n);
	for (int a = 0; a < adjacents.size(); a++) {
		for (int b : adjacents[a]) adjacents_t[b].insert(a);
	}

	set<set<int>> scc_set;
	for (int i = 0; i < n; i++) visited[i] = not visited[i];
	for (int start = postorder.size() - 1;;) {
		while (start >= 0 and visited[postorder[start]] == true) start--;
		if (start == -1) break;
		set<int> scc;
		GetScc(scc, adjacents_t, postorder[start], visited);
		scc_set.insert(scc);
	}

	return scc_set;
}

int Solve() {
	int n, m;
	cin >> n >> m;
	vector<unordered_set<int>> adjacents(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adjacents[a - 1].insert(b - 1);
	}

	set<set<int>> scc_set = IntoSccSet(n, adjacents);
	int numof_explosion = 0;
	for (const set<int>& scc : scc_set) {
		int size = scc.size();
		if (size >= 2) numof_explosion += size;
	}

	if (numof_explosion == 0) cout << "Happy" << endl;
	else cout << numof_explosion << endl;

	return 0;
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
