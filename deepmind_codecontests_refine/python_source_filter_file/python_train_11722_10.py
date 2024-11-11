import sys
from math import gcd, sqrt

sys.setrecursionlimit(10 ** 5)
input = sys.stdin.readline

inf = float("inf")
en = lambda x: list(enumerate(x))

ii = lambda: int(input())
r = lambda: map(int, input().split())
rr = lambda: list(r())


n, k = r()
arr = rr()
ans = 0
z = n - k + 1
for i, j in enumerate(arr, 1):
    ans += j * min(i, n - i + 1, k)

print(ans / z)
