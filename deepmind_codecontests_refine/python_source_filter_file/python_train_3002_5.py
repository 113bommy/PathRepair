import math
n=int(input())
l=[list(map(int,input().split())) for i in range(n)]
pi=math.pi
hl=[[pi,0,0,-pi] for i in range(n)]
for i in range(n):
    x1,y1=l[i]
    for j in range(i+1,n):
        x2,y2=l[j]
        if x1==x2:
            if y1>y2:
                hl[i][3]=0
                hl[j][0]=0
            else:
                hl[j][3]=0
                hl[i][3]=0
        else:
            r=math.atan((y2-y1)/(x2-x1))+pi/2
            if x2>x1:
                hl[j][3]=max(hl[j][3],r-pi)
                hl[j][0]=min(hl[j][0],r)
                hl[i][1]=max(hl[i][1],r)
                hl[i][2]=min(hl[i][2],r-pi)
            else:
                hl[i][3]=max(hl[i][3],r-pi)
                hl[i][0]=min(hl[i][0],r)
                hl[j][1]=max(hl[j][1],r)
                hl[j][2]=min(hl[j][2],r-pi)
for i in hl:
    a,b,c,d=i
    print((max(0,a-b)+max(0,c-d))/(2*pi))