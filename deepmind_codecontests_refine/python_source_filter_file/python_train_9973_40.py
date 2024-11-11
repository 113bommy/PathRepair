import sys,math
input=sys.stdin.readline
n=int(input())
xy=[list(map(int,input().split())) for _ in range(n)]
ans=0
for i in range(75):
    x=math.cos(2*math.pi*i/75)
    y=math.sin(2*math.pi*i/75)
    ax=0
    ay=0
    for dx,dy in xy:
        if x*dx+y*dy>=0:
            ax+=dx
            ay+=dy
    ans=max(ans,(ax**2+ay**2)**0.5)
print(ans)
