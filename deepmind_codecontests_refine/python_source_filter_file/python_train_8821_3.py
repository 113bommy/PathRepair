x,k=map(int,input().split())
MOD = pow(10,9)+7
def repow(n):
  global MOD
  if n == 1:
    return 2
  if n%2 == 0:
    return pow(repow(n//2),2)%MOD
  else:
    return (2*pow(repow(n//2),2))%MOD

if 0 < k and 0 < x:
  if MOD <= k:
    while MOD <= k:
      k = (k // MOD) + (k % MOD)
  tmp = (2*x-1)%MOD
  print((tmp*repow(k)+1)%MOD)
else:
  print(2*x)
