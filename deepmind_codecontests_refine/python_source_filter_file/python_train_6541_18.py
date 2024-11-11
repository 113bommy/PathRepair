N, C = map(int, input().split())
T = [[0 for k in range(100000)] for k in range(C)]

for k in range(N):
    s, t, c = map(int, input().split())
    T[c-1][s-1] += 1
    T[c-1][t] -= 1
for l in range(C):
    for k in range(1,100000):
        T[l][k] += T[l][k-1]

ans = 0
for k in range(100000):
    t = 0
    for l in range(C):
        if T[l][k]:
            t += 1
    ans = max(ans, t)

print(ans)
