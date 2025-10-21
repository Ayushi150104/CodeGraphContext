#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> res;
        vector<string> path;

        // Precompute palindromes using DP
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                }
            }
        }

        backtrack(0, s, dp, path, res);
        return res;
    }

private:
    void backtrack(int index, string &s, vector<vector<bool>> &dp,
                   vector<string> &path, vector<vector<string>> &res) {
        if (index == s.size()) {
            res.push_back(path);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            if (dp[index][i]) {  // use precomputed palindrome check
                path.push_back(s.substr(index, i - index + 1));
                backtrack(i + 1, s, dp, path, res);
                path.pop_back();
            }
        }
    }
};
