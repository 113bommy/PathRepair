N=int(input())
A=list(map(int,input().split()))
I=2*N
D=[[-I]*(N+1)for _ in range(N+1)]
M=0
r=[-I]*(N+1)
def c(i,j,k):
    DP[i][j]=max(k,D[i][j])
    DP[j][i]=max(k,D[j][i])
    r[i]=max(r[i],D[i][j])
    r[j]=max(r[j],D[i][j])
    global M
    M=max(M,k)
a=0
D[A[0]][A[1]]=0
D[A[1]][A[0]]=0
r[A[0]]=0
r[A[1]]=0
for i in range(N-1):
    n=A[3*i+2:3*i+5]
    C=[]
    if len(set(n))==1:
        a+=1
        continue
    if len(set(n))==2:
        for j in range(3):
            if n.count(n[j])==2:
                X=n[j]
            else:
                Y=n[j]
        for j in range(1,N+1):
            C.append((j,Y,D[X][j]+1))
    X,Y,Z =n
    C.append((X,Y,D[Z][Z]+1))
    C.append((Y,Z,D[X][X]+1))
    C.append((X,Z,D[Y][Y]+1))
    C.append((X,Y,M))
    C.append((X,Z,M))
    C.append((Y,Z,M))
    for j in range(1,N+1):
        for k in range(3):
            C.append((j,n[k],r[j]))
    for j,k,l in change:
        c(j,k,l)
M=max(M,D[A[-1]][A[-1]]+1)
print(a+M)