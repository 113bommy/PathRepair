import math
import sys
from collections import Counter

def solve():
    n, m = [int(x) for x in input().split()]
    L, R = 1, n
    for line in sys.stdin:
        x, y = [int(x) for x in line.split()]
        x, y = min(x, y), max(x, y)
        L, R = max(L, x), min(R, y)
        
    return max(R - L, 0)

print(solve())

