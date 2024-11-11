N, M = map(int, input().split())
A = list(map(int, input().split()))
from fractions import gcd
def Lcm(x):
  L = 1
  for a in x:
    a=a//2
    L = (a // gcd(a, L))*L
  return L
X=Lcm(A)
fg = 0
for i in A:
  if (X//i)%2==0:
    fg=1
    break
if fg==1:
  print(0)
else:
  print(((M//X)+1)//2)