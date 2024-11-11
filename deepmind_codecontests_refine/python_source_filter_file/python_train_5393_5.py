a,b,c,d = map(int,input().split())
a -= 1
from math import gcd
g = c*d//gcd(c,d)
cc = b//c-a//c
dc = b//d-a//d 
gc = b//g-a//b
print(b-a-cc-dc+gc)