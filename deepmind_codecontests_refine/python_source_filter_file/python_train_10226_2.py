from collections import deque 
qu = deque(maxlen=200005)

n, m = map(int, input().split())
dist = {}
ls = list(map(int, input().split()))
for i in ls:
    dist[i] = 0
    qu.append(i)

res = []
flag = True
while flag:
    x = qu.popleft()
    for dx in [-1, 1]:
        nx = x + dx
        if nx in dist:
            continue
        dist[nx] = dist[x] + 1
        qu.append(nx)
        res.append(nx)
        if len(res) == m:
            flag = False
            break

ans = sum(dist.values())
print(ans)        
print(' '.join(map(str, res)))