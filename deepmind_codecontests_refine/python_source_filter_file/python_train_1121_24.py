n,m,*l = map(int, open(0).read().split())
l=iter(l)
l=list(zip(l,l,l))
l1=l[:n]
l2=l[-m:]

V=set([float('inf'),-float('inf')])
H=set([float('inf'),-float('inf')])

for a,b,c in l1:
    V.add(c)
    H.add(a)
    H.add(b)
for c,a,b in l2:
    H.add(c)
    V.add(a)
    V.add(b)

V=sorted(list(V))
H=sorted(list(H))
Vdic={}
Hdic={}
for i,v in enumerate(V):
    Vdic[v]=i
for i,h in enumerate(H):
    Hdic[h]=i

checkv=[[0]*3001 for i in range(3001)]
checkh=[[0]*3001 for i in range(3001)]
check=[[0]*3001 for i in range(3001)]

for a,b,c in l1:
    c=Vdic[c]
    for i in range(Hdic[a],Hdic[b]):
        checkh[c][i]=1
for c,a,b in l2:
    c=Hdic[c]
    for i in range(Vdic[a],Vdic[b]):
        checkv[i][c]=1

from bisect import bisect_left
pv=bisect_left(V,0)-1
ph=bisect_left(V,0)-1

ans=0

stack=[(pv,ph)]
check[pv][ph]=1

while stack:
    v,h=stack.pop()
    ans+=(V[v+1]-V[v])*(H[h+1]-H[h])
    if h!=0 and checkv[v][h]==0 and check[v][h-1]==0:
        stack.append((v,h-1))
        check[v][h-1]=1
    if h!=len(H)-2 and checkv[v][h+1]==0 and check[v][h+1]==0:
        stack.append((v,h+1))
        check[v][h+1]=1
    if v!=0 and checkh[v][h]==0 and check[v-1][h]==0:
        stack.append((v-1,h))
        check[v-1][h]=1
    if v!=len(V)-2 and checkh[v+1][h]==0 and check[v+1][h]==0:
        stack.append((v+1,h))
        check[v+1][h]=1

print("INF" if ans==float('inf') else ans)