from collections import deque
n,m = map(int,input().split())
g = [[] for _ in range(n)]
for i in range(m):
    a, b = map(int,input().split())
    g[a-1].append(b-1)
    g[b-1].append(a-1)

checked = [False]*n
q = deque([])
cnt = 0

#連結成分のカウント

for i in range(n):
    if checked[i]:
        continue
    checked[i] = True
    q.append(i)
    while q:
        v = q.pop()
        s = g[v]
        for j in s:
            if checked[j]:
                continue
            checked[j] = True
            q.append(j)
    cnt += 1

print(cnt - 1)