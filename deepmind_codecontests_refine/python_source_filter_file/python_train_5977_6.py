import math
n=int(input())
a=sorted([int(_) for _ in input().split()])
b=0
for i in a:
    b=math.gcd(b,i)
c=(a[0]-1)/b
for i in range(n-1):
    c+=(a[i+1]-a[i]-1)/b;
if c%2==0: print("Bob")
else: print("Alice")