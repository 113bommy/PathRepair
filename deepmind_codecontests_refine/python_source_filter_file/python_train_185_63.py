'''
Created on 2020/08/26

@author: harurun
'''
def factorize(n):
    b = 2
    fct = []
    while b * b <= n:
        while n % b == 0:
            n //= b
            fct.append(b)
        b = b + 1
    if n > 1:
        fct.append(n)
    return fct

def main():
  import math
  import sys
  pin=sys.stdin.readline
  pout=sys.stdout.write
  perr=sys.stderr.write
  N,P=map(int,pin().split())
  l=factorize(P)
  d=list(set(l))
  ans=1
  for i in d:
    t=l.count(i)
    if t>=N:
      ans*=i*(int(t/N))
  print(ans)
  return

main()