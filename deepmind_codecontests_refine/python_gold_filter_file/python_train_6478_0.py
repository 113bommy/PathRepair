import math
n=int(input())
a=list(map(int,input().strip().split()))
b=list(map(int,input().strip().split()))
c=0
d=0
for i in range(n):
    if a[i]==1 and b[i]==0:
        c=c+1
    if a[i]==0 and b[i]==1:
        d=d+1
if d==0 and c>0:
    print(1)
elif d==0 and c==0:
    print(-1)
elif c==0:
    print(-1)
else:
    print(d//c+1)