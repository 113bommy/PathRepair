import math
n=int(input())
m=int(input())
l=int(math.log2(m))
if(l<n):
    print(m)
else:
    print(m%pow(2,n))