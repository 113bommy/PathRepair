# AGC C Ants on a Circle
f=lambda:map(int,input().split())
N,L,T=f()
X,W=[],[]
for _ in [0]*N:
    x,w=f()
    X.append(x)
    W.append(w)
    
if W[0]==2:
    X[0]+=L
    
col=0
for j in range(N):
    if W[j]==W[0]:
        continue
    else:
        if W[0]==1:
            if 2*T-(X[j]-X[0])>=0:
                col+=(1+(2*T-(X[j]-X[0]))//L)
        else:
            if 2*T-(X[0]-X[2])>=0:
                col-=(1+(2*T-(X[0]-X[2]))//L)

col=col%N
X2=[(X[i]+(3-2*W[i])*T) % L for i in range(N)]
X2_0=X2[0]

X2.sort()

index=[i for i,x in enumerate(X2) if x==X2_0]

if len(index)==1:
    index=index[0]
else:
    if W[0]==1:
        index=index[1]
    else:
        index=index[0]

i=(index-col)%N

X2=X2[i:]+X2[:i]
print(*X2,sep='\n')