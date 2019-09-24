/**
 * Leetcode 1155: Number of Dice Rolls With Target Sum
 * Author: Weiqi Feng
 * Date: September 25, 2019
 * Mail: fengweiqi@sjtu.edu.cn
 */ 
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::min;

class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        // Big module number
        constexpr int kMod = 1e9 + 7;
        
        // DP vector: possible ways to get target number
        vector<int> dp(target + 1);
        // There are 1 possible ways to get target 0 with 0 dice
        dp[0] = 1;

        for (int j = 1; j <= d; j++) {
            for (int k = target; k >= 0; k--) {
                dp[k] = 0;
                for(int current = 1; current <= min(k, f); ++current) {
                    dp[k] = (dp[k] + dp[k - current]) % kMod; 
                }
            }
        }
        return dp[target];
    }
};

int main() {
    Solution a;
    cout << a.numRollsToTarget(1, 6, 3) << endl;
    cout << a.numRollsToTarget(2, 6, 7) << endl;
    cout << a.numRollsToTarget(2, 5, 10) << endl;
    cout << a.numRollsToTarget(1, 2, 3) << endl;
    cout << a.numRollsToTarget(30, 30, 500) << endl;
}