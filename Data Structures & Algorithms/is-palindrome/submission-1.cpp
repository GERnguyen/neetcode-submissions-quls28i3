class Solution {
private:
    string me(string s) {
        for (int i = 0; i < s.length(); i++) {
            if (!isalnum(s[i])) {
                s.erase(s.begin() + i);
                i--;
            }
            if (isupper(s[i])) s[i] = tolower(s[i]);
        }
        return s;
    }
public:
    bool isPalindrome(string s) {
        s = me(s);

        int left = 0;
        int right = s.length() - 1;

        cout<<s;
        while (left != right && left < right) {
            if (tolower(s[left]) != tolower(s[right])) {
                cout<<left;
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
