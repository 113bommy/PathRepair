# 解説 imos
n, C = map(int, input().split())
L = [tuple(map(int, input().split())) for _ in range(n)]
m = 10 ** 5
S = [0] * m
for i in range(1, C + 1):
    T = [0] * (m + 1)
    for s, t, c in L:
        if c == i:
            T[s - 1] += 1
            T[t] -= 1
    for i in range(m):
        T[i + 1] += T[i]
    for i in range(m):
        S[i] += T[i]
print(max(S))