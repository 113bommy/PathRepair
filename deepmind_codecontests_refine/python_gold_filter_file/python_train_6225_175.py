import fractions
n,m = map(int,input().split())
print(n*m//fractions.gcd(n,m))