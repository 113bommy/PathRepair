n = int(input())
t = list(map(int, input().split()))
v = list(map(int, input().split()))

T = [0 for i in range(n)]
T[0] = t[0]
for i in range(n-1):
    T[i+1] = T[i] + t[i+1]

INF = float('inf')
V = [INF for i in range(2*T[n-1]+1)]

for i in range(2*t[n-1]+1):
    V[i] = min(V[i], 0.5 * i)
    V[i] = min(V[i], T[n-1] - 0.5 * i)

for vi in range(n):
    for ti in range(2*T[n-1]+1):
        if vi == 0:
            if ti <= T[0] * 2:
                V[ti] = min(V[ti], v[0])
            else:
                V[ti] = min(V[ti], v[0] + ti * 0.5 - T[0])
        else:
            if ti <= T[vi-1] * 2:
                V[ti] = min(V[ti], v[vi] + T[vi-1] - ti * 0.5)
            elif (T[vi-1] * 2 <= ti) and (ti <= T[vi] * 2):
                V[ti] = min(V[ti], v[vi])
            else:
                V[ti] = min(V[ti], v[vi] + (ti * 0.5 - t[vi]))

ans = 0
for i in range(2*t[n-1]):
    ans += (V[i] + V[i+1]) * 0.5 * 0.5

print(ans)