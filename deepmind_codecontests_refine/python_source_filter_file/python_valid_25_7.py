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

def solve():
    s = input()
    t = input()

    if(t in s):
        return True

    if(t[::-1] in s):
        return True

    n = len(s)

    for i in range(n):
        f = t[:i+1]

        if(f == f[::-1] and len(f)%2 == 1):
            rem = t[i+1:]

            half = f[:len(f)//2+1]

            check = rem[::-1] + half

            # print(rem, half, check)

            if(check in s):
                return True

    for i in range(n):
        f = t[i:]

        if(f == f[::-1] and len(f)%2 == 1):
            rem = t[:i]

            half = f[:len(f) // 2 + 1]

            check = rem + half

            if(check in s):
                return True

    return False


for _ in range(stdint()):
    if(solve()):
        print("YES")
    else:
        print("NO")