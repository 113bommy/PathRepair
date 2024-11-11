a,b,c,d=map(int,input().split())
import fractions as f
cc=b//c-(a-1)//c
dd=b//d-(a-1)//d
gcd=f.gcd(c,d)
lcm=c*d//gcd
cd=b//lcm-a//lcm
print((b-a+1)-(cc+dd-cd))