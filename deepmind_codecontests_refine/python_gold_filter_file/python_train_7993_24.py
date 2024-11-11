x,y = map(int,input().split())
mod = 10**9+7
def comb(a,b):
  comb = 1
  chld = 1
  for i in range(b):
    comb = comb*(a-i)%mod
    chld = chld*(b-i)%mod
  return (comb*pow(chld,mod-2,mod))%mod
if (x+y)%3!=0:
  print(0)
else:
  nm = (x+y)//3
  n = y-nm
  m = x-nm
  if n>=0 and m>=0:
    print(comb(n+m,m))
  else:
    print(0)