import math
x=int(input())
print(x*360//(math.gcd(x,360))//x)
