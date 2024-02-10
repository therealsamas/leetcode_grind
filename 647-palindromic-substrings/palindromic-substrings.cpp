
class Solution {
public:
    int counthelper(const string& s, int left, int right) {
        int count = 0;
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
            count++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int ans = 0;
        for (int i =0; i<s.length(); i++) {
            int even = counthelper(s, i, i + 1);
            int odd = counthelper(s, i, i);
            ans += even + odd;
        }
        return ans;
    }
};
