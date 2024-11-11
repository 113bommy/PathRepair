mod=10**9+7
k=int(input())
s=input()
n=len(s)
c=1
t=1
ans=0
m=10**20
for i in range(k+1):
  ans+=c*t
  if ans>m:ans%=mod
  c*=(n+k-i)*pow(i+1,mod-2,mod)
  if c>m:c%=mod
  t*=25
  if t>m:t%=mod
print(ans%mod)
