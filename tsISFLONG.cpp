#include <vector>

using namespace std;

class Solution {
    public:
        long long countSubarrays(vector<int>& nums, long long k) {
            vector<long long> sums;
            long long counts = 0;
            long long sum = 0;
            for(const auto& i : nums){
                sum+= i;
                sums.push_back(sum);
            }
            for(int i = 0; i < nums.size(); i++){
                int max_possible_length = k / nums.at(i);
                for(int j = i; j < i + max_possible_length && j < nums.size(); j++){
                    if(takesum(sums,i,j) < k){counts ++;}
                }
            }
            return counts;
        }
        long long takesum(const vector<long long>& sums, int head, int tail){
            return (sums.at(tail) - sums.at(head)) * (head - tail + 1); 
        }
    };

class Solution2 {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long count = 0;
        long long currentSum = 0;
        int left = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            currentSum += nums[right];
            
            while (left <= right) {
                long long len = right - left + 1;
                
                // Check for potential overflow before multiplication
                if (currentSum > 0 && len > 1e7 / currentSum) {
                    // Use division instead
                    if (k / len <= currentSum) {
                        currentSum -= nums[left];
                        left++;
                        continue;
                    }
                } else {
                    // Safe to multiply
                    if (currentSum * len >= k) {
                        currentSum -= nums[left];
                        left++;
                    } else {
                        break;
                    }
                }
            }
            
            if (left <= right) {
                count += (right - left + 1);
            }
        }
        
        return count;
    }
};
//Sliding window appoarch. Common yet effective for sub arrays related problems
#include <iostream>

int main() {
    
    if (!freopen("tsISFLONG.inp", "r", stdin)) {
        cerr << "Could not open input file" << endl;
        return 1;
    }
    freopen("tsISFLONG.out", "w", stdout);

    int n;
    long long k;
    cin >> n >> k;  // Read array size and target value k

    vector<int> nums;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    Solution2 solution;
    long long result = solution.countSubarrays(nums, k);
    cout << result << endl;

    return 0;
}