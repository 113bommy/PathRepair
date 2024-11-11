N, M = map(int, input().split())
PY = [list(map(int, input().split())) + [i] for i in range(M)]
PY.sort(key=lambda x: [x[0], x[1]])
ans = []
P = [0] * (N + 1)
for p, y, i in PY:
    P[p] += 1
    tmp = str(p).zfill(8) + str(P[p]).zfill(8)
    ans.append([i, tmp])
ans.sort()
for i, a in ans:
    print(a)