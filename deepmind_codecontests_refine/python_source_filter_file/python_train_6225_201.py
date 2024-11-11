import fractions
a,b = map(int,input().split())

g = a*b/fractions.gcd(a,b)
print(g)
