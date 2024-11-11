import sys


def solve(n):
    for j in range(3, 360):
        z = 180 - 360 / j
        if z == n:
            return "YES"
        elif z > n:
            return "NO"
    return "NO"


t = int(input())
for i in range(t):
    n = int(sys.stdin.readline())
    print(solve(n))