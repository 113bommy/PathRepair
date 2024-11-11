import math
n=int(input())
m=int(input())
x=math.log(m,2)
if n>=x:
    print(m)
else:
    k=int(2**n)
    print(m%k)