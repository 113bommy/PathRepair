N,K=map(int,input().split())
A=list(map(int,input().split()))

M=[N]*N

for i in range(K):
    L=[0]*(N+1)
    for j in range(N):
        L[max(0,j-A[j])]+=1
        L[min(N,j+A[j]+1)]-=1
        
    S=0
    for j in range(N):
        S+=L[j]
        A[j]=S

    #if A==M:
    #    break

for i in range(N):
    print(A[i],end=" ")
print()
