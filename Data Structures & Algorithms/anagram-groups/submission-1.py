class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagram_group = defaultdict(list)

        for s in strs:
            sort_s = tuple(sorted(s))
            anagram_group[sort_s].append(s)
        return anagram_group.values()