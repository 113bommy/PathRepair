from collections import Counter
import sys

sys.setrecursionlimit(10 ** 6)

mod = 1000000007
inf = int(1e18)

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]


def inverse(a):
    return pow(a, -1, mod)


def solve():
    n = int(input())
    a = list(map(int, input().split()))
    if a[0] + a[1] < a[-1]:
        print(1, 2, n)
    else:
        print(-1)

def main():
    t = int(input())
    for _ in range(t):
        solve()

main()
