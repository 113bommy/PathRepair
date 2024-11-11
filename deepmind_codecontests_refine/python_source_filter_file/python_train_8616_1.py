mod=10**9+7
k=int(input())
s=input()
l=len(s)
fact=[1]
for i in range(1,k+l+1):
  fact.append((fact[-1]*i)%mod)
revfact=[]
for i in range(k+l+1):
  revfact.append(pow(fact[i],mod-2,mod))
pow1=[1]
pow2=[1]
for i in range(1,k+l+1):
  pow1.append((pow1[-1]*25)%mod)
  pow2.append((pow2[-1]*26)%mod)
ans=0
for i in range(k+l):
  coef1=(pow1[k-i]*pow2[i])%mod
  if i<=k:
    coef2=(fact[k+l-1-i]*revfact[l-1]*revfact[k-i])%mod
  else:
    coef2=0
  ans+=coef1*coef2
  ans%=mod
print(ans)
