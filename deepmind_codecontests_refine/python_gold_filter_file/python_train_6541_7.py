N, C = map(int, input().split())
T = [[0 for k in range(100001)] for l in range(C)]

for k in range(N):
    s, t, c = map(int, input().split())
    T[c-1][s-1] += 1
    T[c-1][t] -= 1
for l in range(C):
    for k in range(1,100001):
        T[l][k] += T[l][k-1]

ans = 0
for k in range(100001):
    t = 0
    for l in range(C):
        if T[l][k] >= 1:
            t += 1
    ans = max(ans, t)

print(ans)
