import sys
from math import*
for e in sys.stdin:
 a,b,c,d,x,y=map(float,e.split(','))
 g=-2*(atan2(y-b,x-a)-atan2(d-b,c-a));s,t=sin(g),cos(g);x-=a;y-=b
 print(f'{t*x-s*y+a:.6f} {s*x+t*y+b:.6f}')
