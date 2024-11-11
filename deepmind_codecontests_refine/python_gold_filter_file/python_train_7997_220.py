import fractions as math
X,Y = [int(x) for x in input().split()]
lcm = X*Y//math.gcd(X,Y)
if(lcm==X):
    print(-1)
else:
    print(X)
