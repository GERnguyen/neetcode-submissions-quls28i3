class Solution {
private:
    string me(string s) {
        string result;

        for (char c: s) {
            if (isalnum(c)) result+=tolower(c);
        }

        return result;
    }
public:
    bool isPalindrome(string s) {
        s = me(s);

        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
