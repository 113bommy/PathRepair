import sys
# gcd
from fractions import gcd
# from math import ceil, floor
# from copy import deepcopy
from itertools import accumulate
from functools import reduce
# from collections import Counter
input = sys.stdin.readline
def ii(): return int(input())
def mi(): return map(int, input().rstrip().split())
def lmi(): return list(map(int, input().rstrip().split()))
def li(): return list(input().rstrip())
# template


def gcd_list(numbers):
    return reduce(gcd, numbers)


n, m = mi()
x = lmi()
sa_x = [x[i + 1] - x[i] for i in range(0, n - 1)]
p = lmi()
gcd_sa_x = gcd_list(sa_x)
# print(gcd_sa_x)
for i in range(0, m - 1):
    if gcd_sa_x % p[i] == 0:
        print('YES')
        print(x[0], i + 1)
        break
else:
    print('NO')
