n=int(input())
a=list(map(int,input().split()))
mod=10**9+7
ans=0
x=1
for i in range(60):
  z=o=0
  for j in range(n):
    if a[j]%2:o+=1
    else:z+=1
    a[j]//=2
  ans+=(x*o*z)%mod
  ans%=mod
  x=(x*2)%mod
print(ans)