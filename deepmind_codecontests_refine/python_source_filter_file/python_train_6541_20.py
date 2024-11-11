from itertools import accumulate
N, C = map(int, input().split())
X = [[0] * (10 ** 5 + 1) for i in range(C)]
for i in range(N):
    s, t, c = map(int, input().split())
    c -= 1
    X[c][s - 1] += 1
    X[c][t] -= 1

for c in range(C):
    X[c] = list(accumulate(list(X[c])))


ans = 0
for i in range(10 ** 5 + 1):
    tmp = 0
    for c in range(C):
        tmp += max(0, X[c][i])
    ans = max(ans, tmp)

print(ans)
