import sys
import math
a,b,c=(map(int,sys.stdin.readline().split(' ')))
ans=-1
for i in range(1,1000):
    a=a*10
    d=a//b
    e=d%10
    if(e==c):
        ans=i
        break
print(ans)