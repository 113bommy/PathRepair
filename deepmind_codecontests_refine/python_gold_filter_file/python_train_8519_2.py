import sys
import collections

sys.setrecursionlimit(10 ** 8)
ini = lambda: int(sys.stdin.readline())
inm = lambda: map(int, sys.stdin.readline().split())
inl = lambda: list(inm())
ins = lambda: sys.stdin.readline().rstrip()
debug = lambda *a, **kw: print("\033[33m", *a, "\033[0m", **dict(file=sys.stderr, **kw))

N = ini()
A = inl()
A.sort()


def solve():
    K = A[-1]
    if A[0] == K:
        return K == N - 1 or (K >= 1 and 2 * K <= N)
    if A[0] != K - 1:
        return False
    counter = collections.Counter(A)
    d = counter[K - 1]
    if K <= d:
        return False
    if N - d <= 1:
        return False
    return 2 * (K - d) <= N - d


print("Yes" if solve() else "No")
