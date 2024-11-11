import math

N=int(input())
P=[list(map(int,input().split())) for i in range(N)]

def div2(x,y):
    if x>0:
        return (1,y/x)
    elif x<0:
        return (-1,y/x)
    else:
        if y>0:
            return (-1,-float("inf"))
        else:
            return (1,-float("inf"))

P.sort(key=lambda x:div2(x[0],x[1]))

ANS=0

for i in range(N):
    for j in range(i,N):
        x0=y0=0
        x1=y1=0

        for k in range(N):
            if i<=k<=j:
                x0+=P[k][0]
                y0+=P[k][1]
            else:
                x1+=P[k][0]
                y1+=P[k][1]

        ANS=max(ANS,x0**2+y0**2,x1**2+y1**2)

print(math.sqrt(ANS))
