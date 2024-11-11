import math
x,y=map(int,input().split())
print(int((x*y)/math.gcd(x,y)))