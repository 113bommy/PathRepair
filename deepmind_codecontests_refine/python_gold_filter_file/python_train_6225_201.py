import fractions
a,b=map(int,input().split())
S=a*b//fractions.gcd(a,b)
print(S)