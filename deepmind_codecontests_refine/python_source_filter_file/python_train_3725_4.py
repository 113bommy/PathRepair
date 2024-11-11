import math
A,B,H,M=map(int,input().split())
c=abs(H*15-M*6)
k=A*A+B*B-2*A*B*math.cos(c*math.pi/360)
l=math.sqrt(k)
print(l)