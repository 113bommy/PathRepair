N, M = map(int, input().split())
G = [[] for i in range(N+1)]
for i in range(M):
    u, v = map(int, input().split())
    G[u].append(v)
s, t = map(int, input().split())

d = [-1] * (N + 1)

S = set()
S.add(s)
d[s] = 0
x = 1
while len(S) > 0:
    Q1 = set()
    for u in S:
        for v in G[u]:
            Q1.add(v)
    Q2 = set()
    for u in Q1:
        for v in G[u]:
            Q2.add(v)
    Q3 = set()
    for u in Q2:
        for v in G[u]:
            if d[v] < 0:
                d[v] = x
                Q3.add(v)
    x += 1
    S = Q3

print(d[t])
