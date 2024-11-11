import fractions
x,y=map(int,input().split())
print((x * y) // fractions.gcd(x, y))
