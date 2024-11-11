import sys
import math
import bisect
from sys import stdin, stdout
from math import gcd, floor, sqrt, log
from collections import defaultdict as dd
from bisect import bisect_left as bl, bisect_right as br
from collections import Counter
from collections import defaultdict as dd

# sys.setrecursionlimit(100000000)

flush = lambda: stdout.flush()
stdstr = lambda: stdin.readline()
stdint = lambda: int(stdin.readline())
stdpr = lambda x: stdout.write(str(x))
stdmap = lambda: map(int, stdstr().split())
stdarr = lambda: list(map(int, stdstr().split()))

mod = 1000000007


k = stdint()

res = 6

for i in range(2, k+1):
    x = pow(4, pow(2, i-1, mod), mod)

    res = (res * x)%mod

print(res%mod)
