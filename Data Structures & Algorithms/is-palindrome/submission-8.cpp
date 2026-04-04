class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;

        if (s.size() == 1) return true;

        while (l <= r) {
            while (!isalnum(s[l]) && l < r) l++;
            while (!isalnum(s[r]) && l < r) r--;

            if (tolower(s[l]) != tolower(s[r])) return false;
            else {
                l++;
                r--;
            }
        }

        return true;
    }
};
