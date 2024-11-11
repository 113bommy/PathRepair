from fractions import gcd
a,b,c,d=map(int,input().split())
c0=b//c-(a-1)//c
d0=b//d-(a-1)//d
cd0=b//(c*d//gcd(c,d))-(a-1)//(c*d//gcd(c,d))
print(b-a+1-c0-d0+cd0)