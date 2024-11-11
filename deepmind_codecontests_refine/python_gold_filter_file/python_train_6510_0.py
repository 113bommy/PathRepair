n = int(input())
d = {}
for i in list(map(int, input().split())):
    if i in d: d[i] += 1
    else: d[i] = 1
m = int(input())
res = [(0, 0)] * m
b = list(map(int, input().split()))
c = list(map(int, input().split()))
for i in range(m):
    if b[i] not in d: d[b[i]] = 0
    if c[i] not in d: d[c[i]] = 0
    res[i] = (d[b[i]], i)
res.sort()
idx = res[m-1][1]
for i in range(m-1, -1, -1):
    if res[i][0] == res[m-1][0] and d[c[res[i][1]]] > d[c[idx]]:
        idx = res[i][1]
print(idx+1)
