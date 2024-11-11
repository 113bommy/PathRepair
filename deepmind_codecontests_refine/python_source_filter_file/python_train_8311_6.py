import sys

sys.setrecursionlimit(10 ** 5)

N = int(input())
T = [[] for _ in range(N)]
for i in range(1, N):
    x = int(input()) - 1
    T[x].append(i)


def f(x):
    candidates = sorted([f(y) for y in T[x]], reverse=True)
    return max((c + i for i, c in enumerate(candidates, 1)), default=0)


print(f(0))
