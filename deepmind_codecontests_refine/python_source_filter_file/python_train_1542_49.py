N=int(input())
A=["*"]+list(map(int,input().split()))
B=["*"]+list([0]*N)

for k in range(N,0,-1):
    p=A[k]
    for i in range(2*k,N+1,k):
        p^=A[i]
    B[k]=p

C=[k for k in range(1,N+1) if B[k]]
print(len(C))
if len(C)!=0:
    print(" ".join(map(str,C)))