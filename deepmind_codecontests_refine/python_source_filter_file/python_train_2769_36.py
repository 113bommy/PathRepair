# cook your dish here
import math
n,m=map(int,input().split())
k=math.gcd(n,m)
k1=math.factorial(min(n,m))
print(k*k1)