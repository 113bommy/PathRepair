
def unionSet(u,v):
    up = findSet(u)
    vp = findSet(v)
    if up == vp:
        return
    else:
        parent[up] = vp
        # cnt[vp] += cnt[up]

def findSet(u):
    if parent[u] != u:
        parent[u] = findSet(parent[u])
    return parent[u]

n,m = map(int,input().split())
if n != m:
    print('NO')
    exit()
parent = list(range(n+1))
for _ in range(m):
    u , v = map(int,input().split())
    unionSet(u,v) # O(n)

cnt = 0
for i in range(1,n):
    if parent[i] == i:
        cnt += 1

if cnt > 1:
    print('NO')
else:
    print('FHTAGN!')
