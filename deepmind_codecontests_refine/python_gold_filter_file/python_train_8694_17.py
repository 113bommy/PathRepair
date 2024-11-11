'''
Created on Apr 28, 2016
Gmail: r.haque.249.rh@gmail.com
@author: Md. Rezwanul Haque
'''
from math import sqrt
a,b,c = map(int,input().split())
d = b**2-4*a*c
x1 = (-b + sqrt(d))/(2*a)
x2 = (-b - sqrt(d))/(2*a)
if(x1>x2):
    print(x1)
    print(x2)
else:
    print(x2)
    print(x1)
