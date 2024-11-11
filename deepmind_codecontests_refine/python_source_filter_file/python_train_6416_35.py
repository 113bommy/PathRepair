from math import *

n =int(input())

x = n%10
if (n>=5):
    print(n+10-x)
else :
    print(n-x)