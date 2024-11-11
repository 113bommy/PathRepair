import sys
import math
import bisect
from sys import stdin, stdout
from math import gcd, floor, sqrt, log
from collections import defaultdict as dd
from bisect import bisect_left as bl, bisect_right as br
from collections import Counter

#sys.setrecursionlimit(100000000)

inp = lambda: int(input())
strng = lambda: input().strip()
jn = lambda x, l: x.join(map(str, l))
strl = lambda: list(input().strip())
mul = lambda: map(int, input().strip().split())
mulf = lambda: map(float, input().strip().split())
seq = lambda: list(map(int, input().strip().split()))

ceil = lambda x: int(x) if (x == int(x)) else int(x) + 1
ceildiv = lambda x, d: x // d if (x % d == 0) else x // d + 1

flush = lambda: stdout.flush()
stdstr = lambda: stdin.readline()
stdint = lambda: int(stdin.readline())
stdpr = lambda x: stdout.write(str(x))
stdarr = lambda: map(int, stdstr().split())

mod = 1000000007
char = {}
j = 0
for i in range(ord('a'), ord('z')+1):
    char[j] = chr(i)
    j += 1

for _ in range(stdint()):
    n = stdint()
    arr = list(stdarr())

    res = []
    m = max(arr)

    if(m == 0):
        for i in range(n+1):
            print(char[i%26])
        continue

    res.append("a"*m)

    j = 1

    for i in range(n):
        if(arr[i] == m):
            res.append(res[-1])
            continue

        n = res[-1][:arr[i]]
        n += char[j%26]*(m-arr[i])
        res.append(n)
        j += 1

    for i in res:
        print(i)
