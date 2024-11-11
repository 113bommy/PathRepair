n=int(input())
m=list(map(int,input().split()))
x=1
from math import fabs
for i in range(1,n):
    if not (-1<=m[i]-m[i-1]<=1):
        x=int(fabs(m[i]-m[i-1]))
        break
for i in range(1,n):
        if not (fabs(m[i]-m[i-1])==x or (m[i]-1)//x==(m[i-1]-1)//x) or m[i-1]==m[i]:  
            print('NO')
            break
else:
    print('YES')
    print(10**9,x)