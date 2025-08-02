#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {  // e.g., "abc", "ahbgdc"
        int idx = 0; 

        for (int i = 0; i < s.size(); i++) {
            bool found = false;
            for (int j = idx; j < t.size(); j++) {
                if (s[i] == t[j]) {
                    idx = j + 1;  
                    found = true;
                    break;  
                }
            }
            if (!found) return false;  
        }
        
        return true;  
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    bool result = s.isSubsequence("aec", "abcde");
    cout << (result ? "true" : "false") << endl;  
    return 0;
}
