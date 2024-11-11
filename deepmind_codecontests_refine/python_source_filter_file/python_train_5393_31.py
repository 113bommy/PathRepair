a,b,c,d=map(int,input().split())
from fractions import gcd
lcm=(c*d)/gcd(c,d)
n=(b//c)-((a-1)//c)
n+=(b//d)-((a-1)//d)
print(b-a+1-n+((b//lcm)-((a-1)//lcm))