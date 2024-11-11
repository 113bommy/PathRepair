import math
for _ in range(int(input())):
    n=int(input())
    x=n//3
    xx=math.ceil(n/3)
    y=n-2*x
    yy=n-2*xx
    if yy>=0 and xx>=0 and abs(y-x)>abs(yy-xx):print(yy,xx)
    else:print(y,x)