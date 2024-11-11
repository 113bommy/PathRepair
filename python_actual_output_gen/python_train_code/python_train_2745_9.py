x,y=map(int,input().split())
mod=10**9+7
def nCr_mod(n,r,mod):
  x=1
  y=1
  for i in range(r):
    x=(x*(n-i)) % mod
    y=(y*(i+1)) % mod
  return (x * pow(y, mod - 2, mod)) % mod
if x*y%3!=0:
  print(0)
else:
  m=int((2*x-y)/3)
  n=int(x-2*m)
  if m<0 or n<0:
    print(0)
  else:
    print(nCr_mod(m+n,n,mod))
