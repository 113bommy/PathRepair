import sys
n, m = map(int, input().split())
G = [[] for _ in range(n)]
cnt = [0]*n
for _ in range(m):
    a, b = map(int, input().split())
    G[a-1].append(b-1)
    G[b-1].append(a-1)
    cnt[a-1]+=1
    cnt[b-1]+=1
if any(cnt[i]%2 == 1 for i in range(n)):
    print('No')
    sys.exit()
c = cnt.count(4)
if any(cnt[i]>=6 for i in range(n)) or c>=3:
    print('Yes')
    sys.exit()
if c<1:
    print('No')
    sys.exit()
v = cnt.index(4)
for v0 in G[v]:
    now = v0
    p = v
    while True:
        for nv in G[now]:
            if nv == p:
                continue
            p = now
            now = nv
            break
        if now == v:
            print('Yes')
            sys.exit()
        if cnt[now] == 4:
            break
print('No')
        