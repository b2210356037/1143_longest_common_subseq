#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        const int n1 = text1.size();
        const int n2 = text2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        for(int i = 1; i <= n1; i++){
            char curr = text1.at(i-1);
            for(int j = 1; j <= n2; j++){
                char curr_iter = text2.at(j-1);
                if(curr == curr_iter){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[n1][n2];
    }
};

int main() {
    Solution s;
    string s1 = "abcdef";
    string s2 = "acbcf";
    int res = s.longestCommonSubsequence(s1, s2);
    cout << res << endl;
    return 0;
}
