
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        unordered_map<char, int> targetCount;
        unordered_map<char, int> windowCount;

        // Count frequency of each character in t
        for (char c : t) targetCount[c]++;

        int required = targetCount.size();  // Number of unique characters in t to be matched
        int l = 0, r = 0;
        int formed = 0;  // Number of unique characters in the current window that match the target count
        int minLength = INT_MAX;
        int start = 0;  // Start index of the minimum window substring

        // Sliding window
        while (r < s.size()) {
            // Add character from the right to the window
            char c = s[r];
            windowCount[c]++;
            if (targetCount.find(c) != targetCount.end() && windowCount[c] == targetCount[c]) {
                formed++;
            }

            // Try to contract the window until it's no longer valid
            while (l <= r && formed == required) {
                c = s[l];

                // Update the minimum window
                if (r - l + 1 < minLength) {
                    minLength = r - l + 1;
                    start = l;
                }

                // Remove character from the left of the window
                windowCount[c]--;
                if (targetCount.find(c) != targetCount.end() && windowCount[c] < targetCount[c]) {
                    formed--;
                }

                l++;  // Move the left pointer
            }

            r++;  // Move the right pointer
        }

        return (minLength == INT_MAX) ? "" : s.substr(start, minLength);
    }
};
