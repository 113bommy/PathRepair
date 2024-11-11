# from collections import namedtuple
# Node = namedtuple("Node", "in, out")
N, M = list(map(int, input().split()))
AB = [list(map(int, input().split())) for _ in range(N+M-1)]
ine = [[] * N for _ in range(N)]
oute = [[] * N for _ in range(N)]
for a, b in AB:
    ine[b-1].append(a-1)
    oute[a-1].append(b-1)
root = ine.index([])
v = [len(e) for e in ine]
print(v)
ans = [0] * N
q = [(root, n) for n in oute[root]]
while q:
    nq = []
    for p, n in q:
        v[n] -= 1
        if v[n] == 0:
            ans[n] = p + 1
            nq += [(n, nn) for nn in oute[n]]
    q = nq

print("\n".join(map(str, ans)))


