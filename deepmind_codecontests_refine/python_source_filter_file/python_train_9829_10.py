from collections import deque, defaultdict, Counter
from itertools import product, groupby, permutations, combinations
from math import gcd, floor, inf
from bisect import bisect_right, bisect_left


n, m = map(int, input().split())
end = False
for i in range(1,n+1):
    s = input()
    if s[-1] == "1" or s[0] == "1":
        end = True
    if i == 0 or i == n:
        if "1" in s:
            end = True

    if end :
        print(2)
        exit()
print(4)






