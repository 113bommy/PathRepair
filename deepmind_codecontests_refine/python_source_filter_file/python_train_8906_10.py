from math import *
n = int(input())

a,b = 1,2
c   =   0

while n > a:
   a,b = b,a+b
   c+=1

print(c)