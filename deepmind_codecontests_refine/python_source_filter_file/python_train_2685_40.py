from fractions import gcd

N,M = map(int,input().split())
a = list(map(int,input().split()))

if len(set([i&-i for i in a])) != 1:
  print(0)
else:
  x = a[0]/2
  for i in range(1, len(a)):
      x = x*(a[i]/2//gcd(x,a[i]/2))

  print(M//x-M//(2*x))