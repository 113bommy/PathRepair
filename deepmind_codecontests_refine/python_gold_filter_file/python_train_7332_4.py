int_inp   = lambda: int(input()) #integer input
strng     = lambda: input().strip() #string input
strl      = lambda: list(input().strip())#list of strings as input
mul       = lambda: map(int,input().split())#multiple integers as inpnut
mulf      = lambda: map(float,input().split())#multiple floats as ipnut
seq       = lambda: list(map(int,input().split()))#list of integers
import math
from collections import Counter,defaultdict

a,b = mul()
k=[]
summ=b+0
for _ in range(a):
    x,y,z = mul()
    k.append([math.sqrt(x**2+y**2),x,y,z])
    summ+=z
if summ<=10**6:
    print(-1)
    exit()
k.sort()
for i in k:
    if b+i[3]>=10**6:
        print(i[0])
        break
    else:
        b+=i[3]
