a,b=map(int,input().split())
import math
gcd=math.gcd(a,b)
print(a*b//gcd)