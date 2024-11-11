from fractions import gcd
A, B, C, D = map(int, input().split())

def f(x):
  l=x//C
  m=x//D
  k=C*D/gcd(C,D)
  n=x//k
  
  return(x-l-m+n)

print(f(B)-f(A-1))