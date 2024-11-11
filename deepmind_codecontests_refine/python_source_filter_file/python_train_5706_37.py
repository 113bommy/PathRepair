import sys
input = sys.stdin.readline

N=int(input())
P=[input().split() for i in range(N)]

for i in range(N):
    P[i][0]=int(P[i][0])
    P[i][1]=int(P[i][1])

def ans(Q):
    MINX=10**15
    MAXX=-10**15
    MINY=10**15
    MAXY=-10**15

    for x,y in Q:
        MINX=min(MINX,x)
        MINY=min(MINY,y)
        MAXX=max(MAXX,x)
        MAXY=max(MAXY,y)

    return (MAXX-MINX)*(MAXY-MINY)
    
def time(t):
    Q=[]
    for x,y,s in P:
        if s=="R":
            x+=t
        elif s=="L":
            x-=t
        elif s=="U":
            y+=t
        else:
            y-=t
        Q.append([x,y])

    return Q

MIN=0
MAX=2*10**8

while MAX-MIN>=1:
    #print(MAX,MIN)
    x=(MIN+MAX)//2

    if ans(time(x))>ans(time(x+1/2)):
        MIN=x+1/2
    else:
        MAX=x

        
print(min(ans(time(MAX)),ans(time(MIN))))
