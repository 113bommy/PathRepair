n,k=map(int,input().split())
import math
l=math.ceil(n/2)
if k<l:
    print(2*k-1)
else:
    print(2*(k-l))