#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class solution{
    public:
    int lengthOfLongestSubstring(string s) {
        int maxlength = 0; int left = 0;
        unordered_set<char>tracker;
        for(int right = 0; right<s.length(); ++right){
            while(tracker.find(s[right]) != tracker.end()){
                tracker.erase(s[left]);
                left++;
            }
            tracker.insert(s[right]);

            maxlength = max(maxlength, right - left + 1);
        }
        return maxlength;
    }
};
class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int n = s.size();
            if(n<2) return n;
    
            int left = 0;
            int result = 0;
    
            vector <int> lastIdx(256, -1);
    
            for(int right = 0; right<n;right++)
            {
                if(lastIdx[s[right]]>=left)
                {
                    left = lastIdx[s[right]]+1;
                    lastIdx[s[right]] = right;
                    
                }
                else if(lastIdx[s[right]]<=left)
                {
                    lastIdx[s[right]] = right;
                }
    
                if((right-left)>result) result = (right-left);
    
    
            }
            return result+1;
        }
    };

int main(){
    string inp = "";
    for(int i = 0; i < 50000; i++){
        inp += char(int('a') + rand()%26);
    }
    solution sol1;
    cout<<sol1.lengthOfLongestSubstring(inp);

    return 0;
}