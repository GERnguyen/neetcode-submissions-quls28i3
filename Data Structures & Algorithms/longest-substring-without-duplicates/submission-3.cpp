class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mp;
        int ans = 0;
        int left = 0, right = 0;

        while (right < s.size()) {
            if (mp.find(s[right]) != mp.end() && mp[s[right]] >= left) {
                left = mp[s[right]]+1;
            }
            ans = max(ans, right - left + 1);
            mp[s[right]] = right;
            right++;
        }
        return ans;
    }
};
