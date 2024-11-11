import sys

h, w, m = map(int, input().split())
row = [0]*h
col = [0]*w
bomb = set()
for x in range(m):
    H, W = map(int, input().split())
    bomb.add([H-1, W-1])
    row[H-1] += 1
    col[W-1] += 1

maxrow = max(row)
maxcol = max(col)
ans = maxcol + maxrow - 1
p, q = [], []
for i in range(h):
    if row[i] == maxrow:
        p.append(i)
for i in range(w):
    if col[i] == maxcol:
        q.append(i)

for i in p:
    for j in q:
        if [i, j] not in bomb:
            print(ans + 1)
            exit()
print(ans)
