import collections
import functools
import math
import random
import sys
import bisect
import copy
import io, os

# input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
#
#
input = sys.stdin.readline


def In():
    return map(int, input().split())


def pf(*args, sep=' ', end='\n'):
    print(*args, sep=sep, end=end)
    sys.stdout.flush()


def art():
    for _ in range(int(input())):
        n, l, r = In()
        last = 0
        ans = 0
        for i in input().split():
            i = int(i)
            ans += max(i - last, 0)
            last = i
        print(ans)


# art()
def ab():
    n = int(input())
    gcf = 0
    m = 0
    for i in input().split():
        i = int(i)
        m = max(i,m)
        gcf = math.gcd(gcf,i)
    print(['Alice','Bob'][not (m//gcf-n)%2])
ab()