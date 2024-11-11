from bisect import bisect_right

N, D, A = map(int, input().split())
X = [list(map(int, input().split())) for _ in range(N)]

x = []
h = []
for d, i in sorted(X):
    x.append(d)
    h.append(i)

ans = 0
k = [-(-v // A) for v in h]
y = [0] * (N + 2)
for i in range(N):
    y[i + 1] += y[i]
    s = max(0, k[i] - y[i + 1])
    ans += s
    y[i + 1] += s
    y[bisect_right(x, x[i] + 2 * D) + 1] -= s
    
print(ans)
