import math
X = int(input())
print((X*360//math.gcd(X, 360))//X)