from fractions import gcd
n,k=map(int,input().split())
a=list(map(int,input().split()))
b=float('inf')
if k>max(a):
  print('IMPOSSIBLE')
else:
  for i in range(n):
    b=min(gcd(a[0],a[i]),b)
  if k%b==0:
     print('POSSIBLE')
  else:
    print('IMROSSIBLE')
    