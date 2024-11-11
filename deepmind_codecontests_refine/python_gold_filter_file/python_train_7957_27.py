import sys
import math

s = sys.stdin.readline()
k = int(sys.stdin.readline())
w = [int(x) for x in (sys.stdin.readline()).split()]

vamx = max(w)
vsum = 0
lenstr = len(s) - 1

for i in range(lenstr):
    vsum += w[ord(s[i]) - ord('a')] * (i + 1)

vsum += int(((2 * vamx * (lenstr + 1)) + (vamx * (k - 1))) / 2 * k)
print(vsum)