H,W,D=map(int,input().split())
A=[list(map(int,input().split())) for _ in range(H)]
Q=int(input())
X=[[0,0] for _ in range(H*W+1)]
for i in range(H):
    for j in range(W):
        X[A[i][j]][0]=i
        X[A[i][j]][1]=j
M=[0]*(H*W+1)
for d in range(D+1,H*W+1):
        M[d]=abs(X[d][0]-X[d-D][0])+abs(X[d][1]-X[d-D][1])+M[d-D]

for i in range(Q):
    L,R=map(int,input().split())
    print(M[R]-M[L])