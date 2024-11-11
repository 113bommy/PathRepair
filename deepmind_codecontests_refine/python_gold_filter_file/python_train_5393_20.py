from fractions import gcd
a,b,c,d = map(int,input().split())
g = c*d//gcd(c, d)
print(b-a+1 - b//c-b//d+b//g + (a-1)//c+(a-1)//d-(a-1)//g)