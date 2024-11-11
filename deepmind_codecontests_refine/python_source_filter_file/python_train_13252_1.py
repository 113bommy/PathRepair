import math
from functools import reduce

def lcm_base(x, y):
    return x // math.gcd(x, y) * y

def lcm(*numbers):
    return reduce(lcm_base, numbers, 1)

import sys
input = sys.stdin.readline

n,m = map(int,input().split())
a = [list(map(int,input().split())) for i in range(n)]

num = lcm(*[i for i in range(1,17)])

ans = [[num]*m for i in range(n)]

for i in range(n):
    for j in range(i//2,m,2):
        ans[i][j] -= a[i][j]**4

for i in ans:
    print(*i)