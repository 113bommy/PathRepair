mod = 998244353
rng = 4100
fctr = [1]
finv = [1]
for i in range(1,rng):
  fctr.append(fctr[-1]*i%mod)
for i in range(1,rng):
  finv.append(pow(fctr[i],mod-2,mod))
def cmb(n,k):
  if n<0 or k<0:
    return 0
  else:
    return fctr[n]*finv[n-k]*finv[k]%mod
def homo(n,k):
  if n<0 or k<=0:
    return 0
  else:
    return cmb(n+k-1,k-1)
k,n = map(int,input().split())
if k%2 == 0:
  flg = 0
else:
  flg = 1
ans = []
for i in range(3,k+2,2):
  ic = (i-1)//2
  anstmp = 0
  for j in range(ic+1):
    t = homo(n-j,(k-ic*2+j))*cmb(ic,j)*pow(2,j,mod)
    anstmp = (anstmp+t)%mod
  ans.append(anstmp)
  ans.append(anstmp)
if flg:
  anstmp = 0
  for j in range(1,k//2+1):
    t = (homo(n-j,j)*homo(n-j-1,j+1))*cmb(k//2,j)*pow(2,j,mod)
    anstmp = (anstmp+t)%mod
  ans.append(anstmp)
ans2 = ans[:-1]
ans2 = ans2[::-1]
print(*ans,sep="\n")
print(*ans2,sep="\n")