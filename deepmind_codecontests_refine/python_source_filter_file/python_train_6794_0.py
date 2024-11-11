import sys
input = sys.stdin.buffer.readline
 
n,m,k = map(int,input().split())
edge = [[] for _ in range(n)]
 
dg = 10**6
MOD = 10**9+7
 
for _ in range(m):
    u,v,w = map(int,input().split())
    edge[u-1].append(w*dg + v-1)
 
num = [[] for i in range(k+1)]
 
one = set()
 
for i in range(n):
    num[len(edge[i])].append(i)
    edge[i].sort()
 
q = [[0]*(k+1) for i in range(k+1)]
q2 = [[0]*(k+1) for i in range(k+1)]

 
for i in range(1,k+1):
    for j in range(i):
        for e in num[i]:
            go = edge[e][j]%dg
            q[i][j] = (q[i][j] + ((go*go*go%MOD + go +12231312)%MOD)*1213 + 12316)%MOD
            q2[i][j] = (q2[i][j] + (go*go+12231312)*1213 + 12316)%MOD
 
cor = 0
cor2 = 0
for i in range(n):
    cor = (cor + ((i*i*i%MOD + i +12231312)%MOD)*1213 + 12316)%MOD 
    cor2 = (cor2 + (i*i+12231312)*1213 + 12316)%MOD

fac = 1
for i in range(2,k+1):
    fac *= i
 
 
 
res = 0
for w in range(1,fac+1):
 
    tmp = w
    nxt = 0
    nxt2 = 0
    tank = []
    for r in range(k,0,-1):
        tmp,c = divmod(tmp,r)
        tank.append(c)
        nxt = (nxt + q[r][c])%MOD
        nxt2 = (nxt2 + q[r][c])%MOD
    if nxt == cor and nxt2 == cor2:

        res += 1
        
 
print(res)