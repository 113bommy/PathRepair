import sys
n,d,a=map(int,input().split())
xh=[]
xx=[]
for i in range(n):
    x,h=map(int,input().split())
    xx.append(x)
    xh.append((x,h//a+(h%a>0)))
xh.sort()
xx.sort()
dp=[0]*n
import bisect
buf=0
count=0
if d==0:
    for i in range(n):
        count+=xh[i][1]
    print(count)
    sys.exit()
for i in range(n):
    #print(buf)
    buf+=dp[i]
    y=max(xh[i][1]-buf,0)
    count+=y
    buf+=y
    idx=bisect.bisect_left(xx,xx[i]+2*d+1)
    if idx>=n:
        continue
    dp[idx]=-y
    #print(dp,y,buf)
print(count)
