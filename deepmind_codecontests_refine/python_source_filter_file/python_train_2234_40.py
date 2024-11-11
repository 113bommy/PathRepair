import math
n,m=map(int,input().split())
n1=math.ceil(n/2)
c=0
for i in range(n1+1,n+1):
    if i%m==0:
        c=1
        print(i)
        break
if c==0:
    print(-1)