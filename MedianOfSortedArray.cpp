#include <iostream>
#include <vector>

using namespace std;

class solution01 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        int index1 = 0;
        int index2 = 0;
        
        while(index1 < nums1.size() || index2 < nums2.size()) {
            if(index1 >= nums1.size()) {
                merged.push_back(nums2[index2++]);
                continue;
            }
            if(index2 >= nums2.size()) {
                merged.push_back(nums1[index1++]);
                continue;
            }
            if(nums1[index1] <= nums2[index2]) {
                merged.push_back(nums1[index1++]);
            } else {
                merged.push_back(nums2[index2++]);
            }
        }
        
        int total = merged.size();
        if(total == 0) return 0.0;
        
        if(total % 2 == 0) {
            return (merged[total/2 - 1] + merged[total/2]) / 2.0;
        } else {
            return merged[total/2];
        }
    }
};

int main(){
    freopen("MedianOfSortedArray.inp","r",stdin);
    freopen("MedianOfSortedArray.out","w",stdout);
    vector<int> nums1, nums2;
    int n, m, temp;

    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> temp;
        nums1.push_back(temp);
    }

    cin >> m;
    for(int i = 0; i < m; ++i){
        cin >> temp;
        nums2.push_back(temp);
    }

    solution01 sol;
    cout << sol.findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}