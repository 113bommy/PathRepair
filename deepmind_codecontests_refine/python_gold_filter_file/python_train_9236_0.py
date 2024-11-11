import math
n,vb,vs=list(map(int,input().split()))
a=list(map(int,input().rstrip().split()))
x,y=list(map(int,input().split()))
time=ms=float('inf')
ans=0
j=0
for i in range(1,n):
    dis=((a[i]-x)**2 + y**2)**0.5
    j=a[i]
    #print(dis/vs + j/vb)
    if (dis/vs + j/vb) < time or (time==dis/vs + j/vb and  dis<ms):
        ms=dis
    
        time=dis/vs + j/vb
        ans=i
print(ans+1)