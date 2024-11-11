from functools import lru_cache
import sys
import math

mod = 10**9 + 7
inf = float('inf')
def arrInt(): return list(map(int, input().split()))


def solve(n, arr):
    arr.sort()
    ans = -inf

    f = arr[:5]
    l = arr[-5:][::-1]

    for i in range(5):
        x = 1
        for j in range(5 - i):
            x *= f[j]
        for j in range(i):
            x *= l[j]

        ans = max(ans, x)

    print(ans)


if 1 == 2:
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')
else:
    input = sys.stdin.readline

T = int(input())
for _ in range(T):
    n = int(input())
    arr = arrInt()
    solve(n, arr)
