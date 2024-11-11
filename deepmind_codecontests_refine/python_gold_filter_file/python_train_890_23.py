n,m,z = map(int,input().split())
import math
print(z//((m*n)//math.gcd(n,m)))