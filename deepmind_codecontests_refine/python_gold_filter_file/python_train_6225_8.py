import fractions
A,B = map(int, input().split())
print(int(A*B//fractions.gcd(A,B)))