/*
 * Leetcode 1233: Dice Roll Simulation
 * 
 * Author: Weiqi Feng
 * Email: fengweiqi@sjtu.edu.cn
 * Date: October 29th, 2019
 * Copyright 2019 Vic
 */
#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;
class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        // dp array
        vector<vector<long long>> dp(n + 1, vector<long long>(6));
        long long divisor = (1000000000 + 7);
        // init
        for (int i = 0; i < 6; i++) {
            dp[0][i] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for(int j = 0; j < 6; j++) {
                // Update dp[i][j] = sum(dp[i - 1][0 - 5])
                for (int k = 0; k < 6; k++) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][k]) % divisor;
                }
                // Subtract the invalid part dp[i - rollMax[j] - 1][k] (which k != j) from dp[i][j]
                if (i - rollMax[j] - 1 >= 0) {
                    int sum = 0;
                    // sum(dp[i - rollMax[j] - 1][0 - 6])
                    for (int k = 0; k < 6; k++) {
                        sum = (sum + dp[i - rollMax[j] - 1][k]) % divisor;
                    }
                    // Update dp[i][j]
                    dp[i][j] = (((dp[i][j] - (sum - dp[i - rollMax[j] - 1][j]))) + divisor) % divisor;
                } else if (i - rollMax[j] >= 0){
                    // Start from 0
                    dp[i][j] -= 1;
                }
            }
        }

        long long sum = 0;
        for (int i = 0; i < 6; ++i) {
            sum = (sum + dp[n - 1][i]) % divisor;
        }
        return sum;
    }
};

int main() {
    Solution a;
    vector<int> vec1 = {1, 1, 2, 2, 2, 3};
    cout << a.dieSimulator(2, vec1) << endl;
    vector<int> vec2 = {1, 1, 1, 1, 1, 1};
    cout << a.dieSimulator(2, vec2) << endl;
    vector<int> vec3 = {8, 5, 10, 8, 7, 2};
    cout << a.dieSimulator(20, vec3) << endl;;
}