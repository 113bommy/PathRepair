k,n=map(int,input().split())
A=list(map(int,input().split()))
ans=A[0]+k-A[n-1]
for i in range(n-1):
    ans=max(ans,A[i+1]-A[i])
print(k-ans)