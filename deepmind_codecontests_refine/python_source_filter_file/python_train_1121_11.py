I=lambda:[int(i) for i in input().split()]
F=1<<65
n,m=I()
X=set([0,F,-F])
Y=set(X)
R=[]
H=[]
for i in range(n):
    a,b,c=I()
    R.append(((a,b),c))
    Y.add(c)
    X.add(a)
    X.add(b)
 
n+=2
R+=[((-F,F),F),((-F,F),-F)]
 
for i in range(m):
    a,b,c=I()
    H.append((a,(b,c)))
    X.add(a)
    Y.add(b)
    Y.add(c)
 
m+=2
H+=[(F,(-F,F)),(-F,(-F,F))]

xdc={}
c=1
for j in sorted(X):
    xdc[c]=j
    c+=1
nx=c-1
 
ydc={}
c=1
for j in sorted(Y):
    ydc[c]=j
    c+=1
ny=c-1
 
xdcr=dict(zip(xdc.values(),xdc.keys()))
ydcr=dict(zip(ydc.values(),ydc.keys()))
 
V=[[0]*(nx+1+1) for i in range(ny+1+1)]
U=[i[:]for i in V]

for (a,b),c in R:
    U[ydcr[c]][xdcr[a]]+=1
    U[ydcr[c]][xdcr[b]]+=-1
for i in range(ny+1):
    for j in range(nx):
        U[i][j+1]+=U[i][j]
        
for d,(e,f) in H:
    V[ydcr[e]][xdcr[d]]+=1
    V[ydcr[f]][xdcr[d]]+=-1
for j in range(nx+1):
    for i in range(ny):
        V[i+1][j]+=V[i][j]

v=[[0]*(nx+1) for i in range(ny+1)]
q=[(xdcr[0],ydcr[0])]
v[ydcr[0]][xdcr[0]]=1

a=0
while q:
    cx,cy=q.pop()
    a+=(xdc[cx]-xdc[cx+1])*(ydc[cy]-ydc[cy+1])
    for dx,dy in [(-1,0),(1,0),(0,1),(0,-1)]:
        nbx=cx+dx
        nby=cy+dy
        if (0>nbx>=nx)or(0>nby>=ny)or v[nby][nbx]==1:
            continue
        if dy!=0:
            if U[-~dy//2+cy][cx]==0:
                q.append((nbx,nby))
                v[nby][nbx]=1
        else:
            if V[cy][-~dx//2+cx]==0:
                q.append((nbx,nby))
                v[nby][nbx]=1
if a>=F:a='F'
print(a)
