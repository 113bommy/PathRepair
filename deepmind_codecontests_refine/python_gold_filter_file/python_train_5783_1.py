import fractions
n,a,b,p,q=map(int,input().split())
nok=a*b//fractions.gcd(a,b)
if p>q:
    a,b,p,q=b,a,q,p
print((n//b)*q+(n//a-n//nok)*p)

