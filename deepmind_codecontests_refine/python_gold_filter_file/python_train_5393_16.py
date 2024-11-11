import math
a,b,c,d=map(int,input().split())
e=c*d//math.gcd(c,d)
print((b-a+1)-(b//c-(a-1)//c)-(b//d-(a-1)//d)+(b//e-(a-1)//e))