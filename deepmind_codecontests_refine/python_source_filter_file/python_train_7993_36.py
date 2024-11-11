def cmbp(n,k):
    nCk = 1
    MOD = 10**9+7

    for i in range(n-k+1, n+1):
        nCk *= i
        nCk %= MOD

    for i in range(1,k+1):
        nCk *= pow(i,MOD-2,MOD)
        nCk %= MOD
    return nCk
x,y=map(int,input().split())
if (x+y)%3==0:
  n=int((2*y-x)/3)
  m=int((2*x-y)/3)
  if n!=0 and m!=0:
    print(cmbp(m+n,n))
  else:
    print(1)
else:
  print(0)