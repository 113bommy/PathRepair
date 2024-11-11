t=int(input())
import math

res=0
for i in range(0,t-1):
    if math.gcd(i,t-1)==1:
        res+=1
    print(max(1,res))