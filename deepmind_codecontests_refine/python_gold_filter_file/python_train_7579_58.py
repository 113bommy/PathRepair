n,k=map(int,input().split())
a=[int(input()) for i in range(n)]
a.sort()
h=10**9
for i in range(n-k+1):
  h=min(h,a[i+k-1]-a[i])
print(h)