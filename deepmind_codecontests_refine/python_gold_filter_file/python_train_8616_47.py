k=int(input())
s=len(input())

def cmb(n,r,mod):
  if r<0 or n<r:
    return 0
  r=min(r,n-r)
  return g1[n]*g2[r]*g2[n-r]%mod

mod=10**9+7

g1=[1,1]#元table
g2=[1,1]#逆元table
inv=[0,1]#逆元table計算用

for i in range(2,k+s+1):
  g1.append(g1[-1]*i%mod)
  inv.append(-inv[mod%i]*(mod//i)%mod)
  g2.append(g2[-1]*inv[-1]%mod)

ans=1
for i in range(1,k+1):
  ans=(ans*26+cmb(i+s-1,s-1,mod)*pow(25,i,mod))%mod
print(ans)