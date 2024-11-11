n,m = map(int, input().split())
py = [[list(map(int, input().split()))] + [i] for i in range(m)]
py.sort(key=lambda x: [x[0], x[1]])
ans = []
P = [0] * (n + 1)
for p, y, i in py:
    P[p] += 1
    tmp = str(p).zfill(6) + str(P[p]).zfill(6)
    ans.append([i,tmp])
ans.sort()
for i,a in ans:
    print(a)