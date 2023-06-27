#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

string s1, s2;
vvl dp;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> s1 >> s2;
	dp = vvl(s1.length(), vl(s2.length(), 0));

	auto ans = ll{ 0 };
	for (auto i = 0; i < s1.length(); ++i) {
		for (auto j = 0; j < s2.length(); ++j) {
			if (s1[i] == s2[j]) {
				if (0 == i || 0 == j) {
					dp[i][j] = 1;
				}
				else {
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}

				ans = max(ans, dp[i][j]);
			}
		}
	}

	cout << ans;

	return 0;
}