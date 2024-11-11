b,w = map(int,input().split())
flg = 0
if b>w:
  flg = 1
  b,w = w,b
elif b == w:
  for _ in range(b+w):
    print(500000004)
    exit()
mod = 10**9+7
rng = 200100
fctr = [1]
finv = [1]
for i in range(1,rng):
  fctr.append(fctr[-1]*i%mod)
def inv(a):
  return pow(a,mod-2,mod)
def cmb(n,k):
  if n<0 or k<0:
    return 0
  else:
    return fctr[n]*inv(fctr[n-k])*inv(fctr[k])%mod

ans = [500000004]*b
nume = pow(2,b-1,mod)
domi = pow(2,b,mod)
for i in range(b+1,b+w+1):
  domi = domi*2%mod
  nume = nume*2-cmb(i-2,i-b-1)
  if i >= w:
    nume += cmb(i-2,i-w-1)
  nume %= mod
  x = nume*inv(domi)%mod
  if flg:
    ans.append(mod+1-x)
  else:
    ans.append(x)
print(*ans,sep="\n")