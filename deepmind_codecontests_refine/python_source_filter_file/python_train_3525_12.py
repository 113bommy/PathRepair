n=int(input())
ta=[list(map(int, input().split())) for _ in range(n)]
a,b=1,1
import math
for i in range(n):
    x,y=ta[i]
    t=max(-(-a//x),-(b//y))
    a,b=t*x,t*y
print(a+b)