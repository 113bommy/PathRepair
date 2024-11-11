import fractions
a,b=map(int,input().split())
c=a*b/fractions.gcd(a,b)
print(int(c))