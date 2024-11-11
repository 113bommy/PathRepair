import fractions as fc

a,b = map(int, input().split())

print(a*b//fc.gcd(a,b))