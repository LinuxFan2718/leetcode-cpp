#include <iostream>
#include <vector>
#include <map>
#include <tuple>

using namespace std;
// https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> lookUpTable;
        int i = 0;
        for (const int& num : nums) {
            lookUpTable.insert(std::make_pair(num, i));
            auto it = lookUpTable.find(target - num);
            if (it != lookUpTable.end() && it->second != i) {
                return {i, it->second};
            }
            i++;
        }
        return {-1, -1};
    }
};

bool areEquivalent(std::vector<int> v1, std::vector<int> v2) {
    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());
    return v1 == v2;
}

int main() {
    Solution solution;
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> output1 = {0, 1};
    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    vector<int> output2 = {1, 2};
    vector<int> nums3 = {3, 3};
    int target3 = 6;
    vector<int> output3 = {0, 1};
    vector< tuple<vector<int>, int, vector<int>> > examples;
    examples = {{nums1, target1, output1}, 
        {nums2, target2, output2}, 
        {nums3, target3, output3}};

    for (const auto& example : examples) {
        vector<int> nums_copy = get<0>(example);
        vector<int> result = solution.twoSum(nums_copy, get<1>(example));
        cout << "Indices: [" << result[0] << ", " << result[1] << "] ";

        if (areEquivalent(result, get<2>(example))) {
            cout << "correct" << endl;
        } else {
            cout << "wrong" << endl;
        };
    }

    return 0;
}