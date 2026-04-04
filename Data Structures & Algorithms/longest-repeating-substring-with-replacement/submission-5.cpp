class Solution {
public:
    int characterReplacement(string s, int k) {
        map <char, int> mp;

        int Max = 0, result = 0;
        int l = 0, r = 0;

        while (r < s.size()) {
            mp[s[r]]++;
            Max = max(Max, mp[s[r]]);

            if (r - l + 1 - Max > k) {
                mp[s[l]]--;
                l++;
            }
            result = max(result,r - l + 1);
            r++;
        }
        return result;
    }
};
