/**
 * Leetcode 1238: Circular Permutation in Binary Representation 
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
    vector<int> circularPermutation(int n, int start) {
        int binary = gray2binary(n, start);
        int step = 0;
        vector<int> result;
        while (step < (1 << n)) {
            // change binary to gray code
            result.push_back(binary ^ (binary >> 1));
            binary = (binary + 1) % (1 << n);
            step += 1;
        }
        return result;
    }
    int gray2binary(int n, int val) {
        // Convert from gray code to binary
        int binaryBit = 0;
        int grayBit = 0;
        int binary = 0;
        while (n > 0) {
            grayBit = (val >> (n - 1)) & 0x1;
            binaryBit = grayBit ^ binaryBit;
            binary |= binaryBit << (n - 1);
            n--;
        }
        return binary;
    }
};

int main() {
    Solution a;
    auto vec = a.circularPermutation(1, 1);
    for (auto i: vec) {
        cout << i << endl;
    }
}