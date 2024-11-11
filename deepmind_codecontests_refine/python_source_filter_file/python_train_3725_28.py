A,B,H,M=map(int,input().split())
import math
print((A**2+B**2-2*B*A*math.cos(math.radians(6*M-30*H)))**(1/2))