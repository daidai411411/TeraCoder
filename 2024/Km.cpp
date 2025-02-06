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
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
using ll = long long;

void Dfs(unordered_set<int>& cycle, const vector<unordered_set<int>>& adjacents, vector<int>& history, vector<int>& history_rev, int current) {
	if (history_rev[current] != -1) {
		for (int i = history_rev[current]; i < history.size(); i++) cycle.insert(history[i]);
		return;
	}
	history_rev[current] = history.size();
	history.push_back(current);
	for (int adjacent : adjacents[current]) {
		Dfs(cycle, adjacents, history, history_rev, adjacent);
	}
	history_rev[current] = -1;
	history.pop_back();
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

	unordered_set<int> cycle;
	vector<int> history, history_rev(n, -1);
	Dfs(cycle, adjacents, history, history_rev, 0);

	if (cycle.empty()) cout << "Happy" << endl;
	else cout << cycle.size() << endl;
}

int main() {
	Solve();
	return 0;
}