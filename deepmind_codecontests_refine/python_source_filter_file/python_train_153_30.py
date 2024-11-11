from collections import deque, defaultdict, Counter
from itertools import product, groupby, permutations, combinations
from math import gcd, floor, inf
from bisect import bisect_right, bisect_left
from sys import stdin
ans = 0
people = 0

for s in stdin:
    if s.startswith("-"):
        people -= 1
    elif s.startswith("+"):
        people += 1
    else:

        ans += len(s.split(":")[1]) * people
print(ans)








