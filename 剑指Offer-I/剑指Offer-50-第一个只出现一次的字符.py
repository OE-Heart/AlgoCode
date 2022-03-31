class Solution:
    def firstUniqChar(self, s: str) -> str:
        if len(s) == 0: return ' '
        hashTabel = {}
        for c in s:
            hashTabel[c] = not c in hashTabel
        for key in hashTabel.keys():
            if hashTabel[key]: return key
        return ' '