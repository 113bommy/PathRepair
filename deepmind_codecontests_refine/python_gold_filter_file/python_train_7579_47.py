n,k=map(int,input().split())
h=sorted([int(input()) for _ in range(n)])
x=10**9
for i in range(n-k+1):
  x=min(x,h[i+k-1]-h[i])
print(x)