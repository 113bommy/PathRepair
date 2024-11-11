import bisect

N, D, A = map(int, input().split())
XH = [list(map(int, input().split())) for _ in range(N)]

XH.sort()
X, H = zip(*XH)

K = [-(-h // A) for h in H]
L = [0] * (N + 2)

ans = 0
for i in range(N):
    L[i + 1] += L[i]
    s = max(K[i] - L[i + 1], 0)
    ans += s
    L[i + 1] += s
    L[bisect.bisect_right(X, X[i] + 2 * D) + 1] -= s

print(ans)
