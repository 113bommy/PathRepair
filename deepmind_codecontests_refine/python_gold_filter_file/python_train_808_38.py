n=int(input())
a=list(map(int,input().split()))
mod=10**9+7
ans=0
for i in range(60):
  x=1<<i
  z=o=0
  for j in range(n):
    if a[j]&x:o+=1
    else:z+=1
  ans=(ans+((x%mod)*o*z)%mod)%mod
print(ans)