
n=int(input())
a=[int(i) for i in input().split()]
MOD = int(1e9+7)
ans=0
for k in range(60):
  x=0
  t=1<<k
  for i in range(n):
    if a[i]&t:
      x+=1
  c=x*(n-x)*2**k
  ans+=c
print(ans%MOD)

