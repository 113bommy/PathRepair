N,K=map(int,input().split())
X=list(map(int,input().split()))
ans=float('inf')
for l in range(N-K+1):
    r=l+K-1
    ans=min(ans,min(abs(X[l]),abs(X[r]))+X[r]-X[l])
print(ans)