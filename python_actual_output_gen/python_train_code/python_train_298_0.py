mod=998244353
n,k=map(int,input().split())
fact=[1]
for i in range(1,n+1):
  fact.append((fact[-1]*i)%mod)
revfact=[1]
for i in range(1,n+1):
  revfact.append(pow(fact[i],mod-2,mod))
if k>=n:
  print(0)
if k==0:
  print(fact[n])
else:
  ans=0
  for i in range(n-k+1):
    if i%2==0:
      ans+=pow(n-k-i,n,mod)*fact[n-k]*revfact[i]*revfact[n-k-i]
      ans%=mod
    else:
      ans-=pow(n-k-i,n,mod)*fact[n-k]*revfact[i]*revfact[n-k-i]
      ans%=mod
  print((ans*fact[n]*revfact[k]*revfact[n-k]*2)%mod)