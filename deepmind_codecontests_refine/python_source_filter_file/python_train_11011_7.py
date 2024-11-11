N,K=map(int,input().split())
A=list(map(int,input().split()))
for i in range(min(K,20)):
    l=[0]*(N+1)
    c=0
    for j in range(N):
        if j-A[j]>0:
            l[j-A[j]]+=1
        else:
            c+=1
        if A[j]+j<N:
            l[A[j]+j+1]-=1 
    for j in range(N):
        c+=l[j]
        A[j]=c
print(*A)