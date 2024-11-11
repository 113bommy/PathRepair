import sys
from math import gcd
from functools import reduce

def solve():
    n = int(input())
    a = [int(i) for i in input().split()]

    ans = reduce(lcm, a, 1)

    print(ans)

def lcm(a, b):
    return a * b // gcd(a, b)

if __name__ == '__main__':
    solve()