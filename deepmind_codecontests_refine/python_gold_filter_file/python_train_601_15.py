N, M =      map(int, input().split())
S    = list(map(int, input().split()))
T    = list(map(int, input().split()))
assert len(S) == N
assert len(T) == M

modulo = 10 ** 9 + 7

# tab[j][i] = S[i] == T[j]
tab = [[s == t for s in S] for t in T]

# 番兵
for t in tab:
    t.append(1)
tab.append([1] * (len(S) + 1))

# 右下から計算
for j in range(M - 1, -1, -1):
    for i in range(N - 1, -1, -1):
        v  = tab[j + 1][i] + tab[j][i + 1]
        v -= 0 if tab[j][i] else tab[j + 1][i + 1]
        tab[j][i] = v % modulo

print(tab[0][0])
