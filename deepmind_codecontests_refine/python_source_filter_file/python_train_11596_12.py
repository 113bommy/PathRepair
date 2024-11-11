import sys
read = lambda: sys.stdin.readline().strip()
readi = lambda: map(int, read().split())
from collections import *

n, k = readi()
nums = list(readi())

bin1 = bin2 = 0
counts = defaultdict(int)
for i in nums: counts[i] += 1

keys = list(counts.keys())

for key in keys:
    if key in counts:
        if key*k in counts:
            bin2 += counts[key*2]
            counts.pop(k*key)
        bin1 += counts[key]
        counts.pop(key)

print(max(bin1, bin2))
    