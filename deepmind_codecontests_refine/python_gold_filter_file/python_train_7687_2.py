import itertools
N, M = map(int, input().split())

G = {k: set() for k in range(N+1)}
for _ in range(M):
    a, b = map(int, input().split())
    # 無向グラフ
    G[a].add(b)
    G[b].add(a)

ans = 0
for p in itertools.permutations(range(2, N+1)):
    c = 1
    for n in p:
        if n not in G[c]:
            break
        c = n
    else:
        ans += 1

print(ans)
