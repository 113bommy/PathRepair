from fractions import gcd
a,b,c,d = map(int,input().split())
e = int(c*d/gcd(c,d))

print((b-a+1) - (b//c - (a-1)//c) - (b//d - (a-1)//c) + (b//e - (a-1)//e))