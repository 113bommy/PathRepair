import math
A,B,H,M=map(int,input().split())
rad=abs(math.pi/6*H-math.pi/30*M)
print((A**2+B**2-2*A*B*math.cos(rad))**0.5)