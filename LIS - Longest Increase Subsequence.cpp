#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
//This is dynamic programming based approach that can be used for other alikes problems
class Solution1 {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ends;
        for(const int& i : nums){
            int fn = BS(ends, i);
            if(fn == ends.size()){
                ends.push_back(i);
            }else{
                ends[fn] = i;
            }
        }
        return ends.size();
    }
private:
    int BS(vector<int>& nums, int toSearch){
        int left = 0;
        int right = nums.size() - 1;
        
        int resultIndex = nums.size();

        while(left <= right){
            int KeyIndex = left + (right - left)/2;
            if(nums.at(KeyIndex) >= toSearch){
                resultIndex = KeyIndex;
                right = KeyIndex - 1;
            }else{
                left = KeyIndex + 1;
            }
        }
        return resultIndex;
    }
};
//This is brute forcing + recursive based approach
class Solution2 {
public:
    int lengthOfLIS(vector<int>& nums){
        
    }
private:
    int RcLisLength(vector<int>& nums, int begin, vector<int>&result){
        int result = 0;
        for(int i = begin; i < nums.size, i ++){
            if(nums)
        }
    }
};
int main(){
    vector<int> nums = {10,9,2,5,3,7,101,18};
    Solution S;
    cout << S.lengthOfLIS(nums);
}