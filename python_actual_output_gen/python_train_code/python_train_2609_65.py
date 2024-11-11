n,k=map(int,input().split())
h=sorted([int(input()) for _ in range(n)])
ans=10**9
for i in range(n-k):
    ans=min(h[k+i-1]-h[i],ans)
print(ans)