K,N=map(int,input().split())
A=list(map(int,input().split()))
ans=A[0]+K-A[-1]
for i in range(N-1):
    ans=max(ans,A[i+1]-A[i])
print(ans)
