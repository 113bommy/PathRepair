n,k=map(int,input().split())
import math
a=math.ceil(n/2)
if k<=a:
    print(2*k-1)
else:
    print(2*(k-a))