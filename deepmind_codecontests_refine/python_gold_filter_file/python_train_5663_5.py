##__________________________________________________________________
##
## Author:      GogolGrind
##__________________________________________________________________

from sys import *
from math import *

def toContF(a,b):
   r = []
   while b > 0:
      r.append(a//b)
      a %= b
      a,b = b,a
   return r

def main ():
   p,q = list(map(int,input().split()))
   b = toContF(p,q)
   n = int(input())
   a = list(map(int,input().split()))
   if (len(a) > 1 and a[-1] == 1): 
           a[-2] += 1
           a = a[:-1]
   if (len(a) != len(b)):
      print('NO')
      return 0
   for i,j in zip(a,b):
      if (i != j):
         print('NO')
         return 0
   print('YES')
if __name__ == '__main__':
    main()
