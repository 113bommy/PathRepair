n,k=map(int,input().split())
h=sorted(int(input()) for i in range(n))
ans=10**10
for i in range(n-k+1):
    ans=min(h[i+k-1]-h[i],ans)
print(ans)