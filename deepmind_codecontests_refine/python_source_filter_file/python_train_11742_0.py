#from collections import deque,defaultdict
printn = lambda x: print(x,end='')
inn = lambda : int(input())
inl   = lambda: list(map(int, input().split()))
inm   = lambda:      map(int, input().split())
ins = lambda : input().strip()
DBG = True  and False
BIG = 10**18
R = 10**9 + 7
#R = 998244353

def ddprint(x):
  if DBG:
    print(x)

def popcnt(x):
    c = 0
    while x>0:
        c += x%2
        x >>= 1
    return c

def dfs(u,v,p):
    global d
    d[u][v] = p
    for x in dst[v]:
        if u!=x and d[u][x]==0:
            p |= 1<<dst[v][x]
            dfs(u,x,p)
            p ^= 1<<dst[v][x]

n = inn()
dst = [{} for i in range(n+1)]
for i in range(n-1):
    a,b = inm()
    dst[a][b] = dst[b][a] = i

m = inn()
u = []
v = []
for i in range(m):
    uu,vv = inm()
    u.append(uu)
    v.append(vv)

if True and n==2 and m==1:
    print(0)
    exit()

d = [[0]*(n+1) for i in range(n+1)]
for i in range(1,n+1):
    dfs(i,i,0)
dd = []
for i in range(m):
    dd.append(d[u[i]][v[i]])
ddprint(dst)
ddprint(d)
ddprint(u)
ddprint(v)
ddprint(dd)

y = 0
for i in range(1,2**m):
    nbits = x = 0
    for j in range(m):
        if (i>>j)%2>0:
            x |= dd[j]
            nbits += 1
    nsegs = popcnt(x)
    s = 2*(nbits%2)-1
    y += s*2**(n-1-nsegs)
print(2**(n-1)-y)
