from itertools import groupby

S = list(input())
K = int(input())

N = len(S)

if len(set(list(S))) == 1:
    print(N * K // 2)
else:
    G = list(map(lambda g: len(list(g[1])), (groupby(S))))
    cnt = sum(map(lambda g: g // 2, G)) * K

    if S[0] != S[N - 1]:
        print(cnt)
    else:
        a = G[0]
        b = G[-1]
        print(cnt - (a // 2 + b // 2 - (a + b) // 2) * (K - 1))
