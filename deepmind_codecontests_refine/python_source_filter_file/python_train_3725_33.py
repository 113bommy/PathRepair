#C
import math

A,B,H,M = map(int,input().split())
a2 = A*A+B*B-2*A*B*math.cos(math.pi*2*(H/12-M/60))
print(math.sqrt(a2))