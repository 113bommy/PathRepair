n,k=map(int,input().split())
a=[int(input()) for i in range(n)]
a.sort()
x=10**9
for i in range(n-k+1):
  x=min(x,a[i+k-1]-a[i])
print(x)
