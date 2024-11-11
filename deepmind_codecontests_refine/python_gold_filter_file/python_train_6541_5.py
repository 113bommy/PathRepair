# 解説 imos
n, C = map(int, input().split())
L = [tuple(map(int, input().split())) for _ in range(n)]
m = 2 * 10 ** 5 + 2
S = [0] * m
for x in range(1, C + 1):
    T = [0] * m
    for s, t, c in L:
        if c == x:
            # 始点を奇数, 終点を偶数にするのうまい
            T[2 * s - 1] += 1
            T[2 * t] -= 1
    for i in range(1, m):
        T[i] += T[i - 1]
    for i in range(m):
        if T[i] > 0:
            S[i] += 1
print(max(S))