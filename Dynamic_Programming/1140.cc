/**
 * Leetcode 1140: Stone Game II 
 * Author: Weiqi Feng
 * Date: September 25, 2019
 * Mail: fengweiqi@sjtu.edu.cn
 */ 
#include <iostream>
#include <vector>
#include <utility>

using namespace std;
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int length = piles.size();
        vector<int> postSum(length);
        // postSum[i] = sum(piles[i], piles[i+1], ..., piles[length - 1])
        for (int i = length - 1; i >= 0; i--) {
            if (i != length - 1) {
                postSum[i] = piles[i] + postSum[i + 1];
            } else {
                postSum[i] = piles[i];
            }
        }

        // dp[i][j] represents Lee can get maximum number 
        // of stones starting at piles[i] with M = j
        // Lee and Alex actually are equivalent 
        // Game theory problem
        vector<vector <int>> dp(length + 1, vector<int>(length + 1, 0));
        for (int m = 1; m <= length; m++) {
            dp[length - 1][m] = piles[length - 1];
        }
        for (int k = length - 1; k >= 0; k--) {
            for (int m = 1; m <= length; m++) {
                for (int len = 0; (len + 1 <= 2 * m) && (k + len + 1) <= length; len++) {
                    // Alex getting maximum number of stones means that 
                    // remaining stones (postSum[k] - #{Lee get stones}) 
                    // should be maximized
                    dp[k][m] = max(postSum[k] - dp[k + len + 1][max(m, len + 1)], dp[k][m]);
                }
            }
        }

        // return the number of stones that Alex gets from pile[0] with m = 1
        return dp[0][1];
    }

};

int main() {
    Solution a;
    vector<int> piles = {1, 2, 3, 4, 5, 100};
    // Correct answer: 104
    cout << a.stoneGameII(piles) << endl; 
}