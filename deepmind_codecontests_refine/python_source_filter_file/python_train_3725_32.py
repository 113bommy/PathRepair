import math

A, B, H, M = map(int, input().split())

print((A**2+B**2-2*B*math.cos(math.radians(abs((H*60+M)/2-M*6))))**0.5)
