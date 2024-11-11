import math
x,y,m = map(int,input().split())
x,y = min(x,y),max(x,y)

if y >= m:
    print(0)
elif y <= 0:
    print(-1)
else:
    cnt=0
    if x<0:
        cnt += math.ceil((-x)/y)
        x = x + cnt*y 
    while y<m:
        x,y = y,x+y 
        cnt += 1
    print(cnt)

