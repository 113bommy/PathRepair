n=int(input())
f=[list(map(int,input().split()))for _ in range(n)]
p=[list(map(int,input().split()))for _ in range(n)]
ans=0
for bit in range(1,1<<10):
  a=0
  for i in range(n):
    b=0
    for j in range(10):
      if bit&1<<j:b+=f[i][j]
    a+=p[i][b]
  ans=max(a,ans)
print(ans)