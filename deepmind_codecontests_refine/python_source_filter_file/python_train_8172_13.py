from sys import *
from math import *
n=int(stdin.readline())
m=[]
for i in range(n):
    a = list(map(int, stdin.readline().split()))
    m.append(a)
x=[0]*2002
y1=[0]*2002
y2=[0]*2002
for i in range(n):
    x[m[i][0]+m[i][1]]+=1
    v=m[i][0]-m[i][1]
    if v<0:
        y1[abs(v)]+=1
    else:
        y2[v]+=1
ans=0
for i in range(1001):
    if x[i]!=0:
        ans+=((x[i]*(x[i]-1))//2)
    if y1[i]!=0:
        ans+=((y1[i]*(y1[i]-1))//2)
    if y2[i] != 0:
        ans += ((y2[i] * (y2[i] - 1)) // 2)
print(ans)

