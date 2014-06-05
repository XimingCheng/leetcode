class Solution:
    # @param s, a string
    # @return an integer
    def lengthOfLastWord(self, s):
        s = s.strip()
        if(len(s) == 0): return 0
        split_val = s.split(" ")
        if len(split_val) > 0:
            last_idx = len(split_val) - 1
            return len(split_val[last_idx])
        else:
            return 0