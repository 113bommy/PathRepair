mod=10**9+7
k=int(input())
s=input()
n=len(s)
c=1
t=1
ans=0
for i in range(k+1):
  ans+=c*t
  ans%=mod
  c*=(n+k-i)*pow(i+1,mod-2,mod)
  c%=mod
  t*=25
  t%=mod
print(ans)
