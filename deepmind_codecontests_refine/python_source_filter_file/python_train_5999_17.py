import math
from fractions import Fraction as frac

MOD = 1e9 + 7

def solve(case_no):
    n = int(input())
    a = list(map(int, input().split()))
    a = sorted(a)
    print(a[n - 1] - 25)


t = 1
# t = int(input())
for i in range(1, t + 1):
    solve(i)
