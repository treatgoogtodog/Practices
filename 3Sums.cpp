#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution1 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end()); 
        if (nums.size() < 3) return {}; 
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; 
            for (int j = i + 1; j < nums.size() - 1; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int target = -(nums[i] + nums[j]);
                if (binary_search(nums.begin() + j + 1, nums.end(), target)) {
                    result.push_back({nums[i], nums[j], target});
                }
            }
        }

        return result;
    }
};

class Solution2 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            unordered_set<int> seen;
            for (int j = i + 1; j < nums.size(); j++) {
                int complement = -(nums[i] + nums[j]);
                if (seen.count(complement)) {
                    result.push_back({nums[i], nums[j], complement});

                    while (j + 1 < nums.size() && nums[j] == nums[j + 1]) j++;
                }
                seen.insert(nums[j]); 
            }
        }

        return result;
    }
};

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    Solution2 sol;
    vector<vector<int>> result = sol.threeSum(nums);

    for (const auto& triplet : result) {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << endl;
    }

    return 0;
}