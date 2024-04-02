class Solution:
    def reverse(self, x: int) -> int:
        INT_MAX = pow(2, 31) - 1
        INT_MIN = -pow(2, 31)
        s = 1
        if x < 0:
            s = -1
            x = -x
        rev_s = str(x)[::-1]
        rev_n = int(rev_s) * s
        return rev_n if INT_MIN <= rev_n <= INT_MAX else 0
