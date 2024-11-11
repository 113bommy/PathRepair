import math
n=int(input())
b=math.sqrt(n)
a=int(n)
c=0
for i in range(1,a+1):
    if n%i==0:
        c=c+1
if b-a>0:
    print(2*c)
elif b-a==0:
    print((2*c)-1)