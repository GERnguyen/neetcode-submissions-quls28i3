class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int p1 = 0, p2 = 1, limit = numbers.size();
        while (p1 < limit) {
            while (numbers[p1] + numbers[p2] <= target 
                && p2 < limit) {
                if (numbers[p1] + numbers[p2] == target) 
                    return {p1 + 1, p2 + 1};
                p2++;
            }
            p1++;
            limit = p2;
            p2 = p1 + 1;
        }
        return {};
    }
};
