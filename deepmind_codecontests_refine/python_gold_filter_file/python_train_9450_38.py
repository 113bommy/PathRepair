N,K=map(int,input().split())
P=list(map(int,input().split()))

A={k+1:P[k] for k in range(N)}


U=list()
S=set()
x=1
k=0

while (x not in S) and (k<=K):
    U.append(x)
    S.add(x)
    
    x=A[x]
    k+=1

if k>K:
    print(U[-1])
else:
    d=U.index(x)
    V=U[d:]
    print(V[(K-d)%len(V)])
