/**
 * Leetcode 1191: K-Concatenation Maximum Sum
 * Author: Weiqi Feng
 * Date: September 26, 2019
 * Mail: fengweiqi@sjtu.edu.cn
 */ 
#include <vector>
#include <iostream>
#include <utility>
using namespace std;

class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        constexpr int magic = 1e9 + 7;
        // no need for concatenation
        if (k == 1) {
            return NConcatenationMaxSum(arr, 1);
        }
        // Calc the sum of arr
        long long arr_sum = 0;
        for (auto& n: arr) {
            arr_sum += n;
        }
        // if arr_sum <0, we only need consider k = 2
        // since more than 2 concatenation will only
        // reduce the maximum subsum
        if (arr_sum < 0) {
            return NConcatenationMaxSum(arr, 2);
        }
        else {
            // calc the maximum prefixsum and suffixsum
            return ((k - 2) * arr_sum + prefixMaxSum(arr) +  suffixMaxSum(arr)) % magic;
        }
    }

    long long prefixMaxSum(vector<int> &arr) {
        // Calculate prefix sum of arr
        vector<long long> prefixSum(arr.size(), 0);
        long long maxSum = 0;
        for (int i = 0; i < arr.size(); ++i) {
            if (i == 0) {
                prefixSum[i] = arr[i];
            } else {
                prefixSum[i] = arr[i] + prefixSum[i - 1];
            }
            maxSum = max(maxSum, prefixSum[i]);
        }
        return maxSum;
    }

    long long suffixMaxSum(vector<int> &arr) {
        // Calculate suffix sum of arr
        vector<long long> suffixSum(arr.size(), 0);
        long long maxSum = 0;
        for (int i = arr.size() - 1; i >= 0; --i) {
            if (i == arr.size() - 1) {
                suffixSum[i] = arr[i];
            } else {
                suffixSum[i] = arr[i] + suffixSum[i + 1];
            }
            maxSum = max(maxSum, suffixSum[i]);
        }
        return maxSum;
    }



    int NConcatenationMaxSum(vector<int> &arr, int k) {
        constexpr int magic = 1e9 + 7;
        const int len = arr.size() * k;
        // Store maximum sub-array sum
        vector<int> dp(2, 0);
        dp[0] = max(0, arr[0]);
        int max_sum = dp[0];
        for (int i = 1; i < len; ++i) {
            dp[i % 2] = max(0, arr[i % arr.size()] + dp[(i - 1) % 2]);
            max_sum = max(max_sum, dp[i % 2]);
        }
        return max_sum % magic;

    }
};

int main() {
    Solution a;
    vector<int> a1 = {-5,-2,0,0,3,9,-2,-5,4};
    cout << a.kConcatenationMaxSum(a1, 5) << endl;
    vector<int> a2 = {1, -2, 1};
    cout << a.kConcatenationMaxSum(a2, 5) << endl;
    vector<int> a3 = {-1, -2};
    cout << a.kConcatenationMaxSum(a3, 7) << endl;

}