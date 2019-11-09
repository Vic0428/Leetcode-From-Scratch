/*
 * Leetcode 1190: Reverse Substrings Between Each Pair of Parentheses
 * 
 * Author: Weiqi Feng
 * Email: fengweiqi@sjtu.edu.cn
 * Date: November 9th, 2019
 * Copyright 2019 Vic
 */
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    string reverseParentheses(string s) {
        vector<int> reverseLen;
        string res;
        for (int i = 0; i < s.length(); i++) {
            // Push reverse length into vector
            if (s[i] == '(') {
                reverseLen.push_back(res.length());
            } else if (s[i] == ')') {
                reverse(res.begin() + reverseLen.back(), res.end());
                reverseLen.pop_back();
            } else {
                res += s[i];
            }
        }
        return res;
    }
};

int main() {
    string str = "ta()usw((((a))))";
    Solution a;
    cout << a.reverseParentheses(str) << endl;
}