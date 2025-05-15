#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        while (p.find("**") != string::npos) {
            p.erase(p.find("**"), 1); 
        }

        p = redux(p);

        uint16_t _s_indx = 0;
        uint16_t _p_indx = 0;

        while (_p_indx < p.length()) {
            if (_p_indx + 1 < p.length() && p.at(_p_indx + 1) == '*') {
                while (_s_indx < s.length() && (p.at(_p_indx) == '.' || s.at(_s_indx) == p.at(_p_indx))) {
                    _s_indx++;
                }
                _p_indx += 2; 
            } else if (_s_indx < s.length() && (p.at(_p_indx) == '.' || s.at(_s_indx) == p.at(_p_indx))) {
                _s_indx++;
                _p_indx++;
            } else {
                return false; 
            }
        }
        return _s_indx == s.length();
    }

private:
    string redux(const string& p){
        string simplified;
        for (size_t i = 0; i < p.length(); ++i) {
            // Add the current character to the simplified pattern
            simplified += p[i];

            // If the current character is '*', skip redundant characters
            if (p[i] == '*' && i > 0) {
                while (i + 1 < p.length() && p[i + 1] == p[i - 1]) {
                    i++;
                }
            }
        }
        return simplified;
    }
};

int main() {
    Solution sol;

    // Test case
    string s = "aaa";
    string p = "a*a";

    bool result = sol.isMatch(s, p);

    cout << "Is the string \"" << s << "\" matching the pattern \"" << p << "\"? "
         << (result ? "Yes" : "No") << endl;

    return 0;
}