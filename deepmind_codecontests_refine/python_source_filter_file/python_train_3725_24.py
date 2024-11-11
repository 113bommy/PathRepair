import math
A,B,H,M = map(float,input().split())
X = sqrt(A**2+B**2-2*A*B*math.cos(math.radians(5.5*M-30*H)))
print(X)