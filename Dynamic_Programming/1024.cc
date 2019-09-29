/**
 * Leetcode 1024: Video Stitching
 * Author: Weiqi Feng
 * Date: September 29, 2019
 * Mail: fengweiqi@sjtu.edu.cn
 */ 
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b) {
        return a[0] < b[0];
    }

    int videoStitching(vector<vector<int>>& clips, int T) {
        constexpr int MAX = 1000;
        vector<int> dp(T + 1, MAX);
        // Sort clips based on start time
        sort(clips.begin(), clips.end(), cmp);

        // Make sure clips can conver time starting from 0
        if (clips[0][0] != 0) {
            return -1;
        }

        // Only use the first clip: cover from Time 0 to Time min(clips[0][1], T)
        for (int i = 0; i <= min(clips[0][1], T); i ++) {
            dp[i] = 1;
        }
        
        for (int i = clips[0][1] + 1; i <= T; i++) {
            // Start from the first clip
            int j = 0;
            // Ignore clips that can't cover Time i
            while(j < clips.size() && clips[j][1] < i) {
                j++;
            }

            // Can't find clip that cover Time i, jump out of the loop
            if (j == clips.size()) {
                break;
            }

            // Based on dp[k], we update the minimum value dp[i]
            for (int k = max(clips[j][0], 0); k < i; k++) {
                if (dp[k] != MAX) {
                    if (clips[j][0] != 0) {
                        dp[i] = min(dp[k] + 1, dp[i]);
                    } else {
                        dp[i] = 1;
                    }
                }
            }
        }

        // dp[T] still is the preset value => we can't cover [0, T]
        if (dp[T] == MAX) {
            return -1;
        } else {
            return dp[T];
        }
    }
};

int main() {
    Solution a;
    vector<vector<int>> clips = {{3, 6}, {3, 6}, {0, 4}, {6, 6}, {8, 10}, {6, 10}, {0, 1}, {6, 9}};
    int T = 2;
    cout << a.videoStitching(clips, T) << endl;
}