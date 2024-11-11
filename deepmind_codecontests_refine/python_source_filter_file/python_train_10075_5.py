N,S=map(int,input().split())
A=[0]+list(map(int,input().split()))

H=[[0]*(S+1) for i in range(N+1)]

#H[x][y]:1,...xに制限したときに,和がyになるのは何個?
M=998244353

for x in range(N+1):
    H[x][0]=1

for x in range(1,N+1):
    for s in range(S+1):
        if s>=A[x]:
            H[x][s]=2*H[x-1][s]+H[x-1][s-A[x]]
        else:
            H[x][s]=2*H[x-1][s]

print(H[-1][-1])
