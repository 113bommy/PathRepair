import math
A,B,C,D=map(int,input().split())
E=C*D//math.gcd(C,D)
c=B//C-(A-1)//C
d=B//D-(A-1)//D
e=B//E-(A-1)//E
print(B-A+1-c-d+e)