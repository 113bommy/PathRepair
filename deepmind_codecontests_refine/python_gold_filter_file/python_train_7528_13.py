import math
import sys

input = lambda: sys.stdin.readline().rstrip()


def dist(i, j):
    global a
    return abs(a[i] - a[j]) + abs(i - j)


def check(l, r):
    global a
    for i in range(l, r):
        for j in range(l, r):
            for k in range(l, r):
                if i != j and i != k and j != k and dist(i, j) == dist(i, k) + dist(k, j):
                    return 0
    return 1


for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    ans = 0
    for i in range(n):
        ans += sum(check(j, i+1) for j in range(i, max(i - 9, -1), -1))
    print(ans)
