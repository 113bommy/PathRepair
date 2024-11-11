import sys, math
#sys.setrecursionlimit(10**6)
INF = float('inf')
mod = 10**9 + 7
#mod = 998244353
input = lambda: sys.stdin.readline().rstrip()
li = lambda: list(map(int, input().split()))

t = int(input())

def check(x, N, H):
    for i in range(N-1):
        H -= min(A[i+1] - A[i], x)
    H -= x
    return H <= 0


for _ in range(t):
    N, H = li()
    A = li()

    ok = 10 ** 18 + 1
    ng = -1
    while ok - ng > 1:
        mid = (ok + ng) // 2
        if check(mid, N, H):
            ok = mid
        else:
            ng = mid
    print('yes', ok)
