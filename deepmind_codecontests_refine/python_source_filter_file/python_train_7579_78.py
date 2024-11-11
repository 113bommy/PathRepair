n,k=map(int,input().split())
L=sorted([int(input()) for _ in range(n)])
ans=10**10
for i in range(n-k):
    ans=min(L[i+k-1]-L[i],ans)
print(ans)