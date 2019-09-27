/**
 * Leetcode 1043: Partition Array for Maximum Sum 
 * Author: Weiqi Feng
 * Date: September 27, 2019
 * Mail: fengweiqi@sjtu.edu.cn
 */ 
#include <vector>
#include <iostream>
#include <utility>

using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        const int len = A.size();
        vector<int> dp(len, 0);
        // init dp array dp[i] stands for maximum results
        // in subarray A[0..i] under problem conditions
        dp[0] = A[0];
        for (int i = 1; i < len; i++) {
            // A little trick: consider dp[i - 1], dp[i - 2], .. in decreasing order
            int max_element = A[i];
            for (int j = i - 1; j >= max(-1, i - K);j--) {
                max_element = max(max_element, A[j + 1]);
                // j == -1 => from A[0..j] as a whole subarray
                if (j != -1) {
                    dp[i] = max(dp[j] + (i - j) * max_element, dp[i]);
                } else {
                    dp[i] = max((i - j) * max_element, dp[i]);
                }
            }
        }
        return dp[len - 1];
    }
};

int main() {
    Solution a;
    vector<int> A = {1, 15, 7, 9, 2, 5, 10};
    cout << a.maxSumAfterPartitioning(A, 3) << endl;
}