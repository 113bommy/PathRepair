n,k=map(int,input().split())
h=[int(input()) for i in range(n)]
h.sort()
ans=10000000
for i in range(n-k+1):
  ans=min(h[i+k-1]-h[i],ans)
print(ans)