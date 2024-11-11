def cal(i,j):
    if i==1 and j==1: return "R"
    elif i==1 and j==0: return "U"
    elif i==0 and j==1: return "D"
    elif i==0 and j==0: return "L"



import sys

N=int(input())


a=[list(map(int,input().split())) for i in range(N)]
mod=sum(a[0])%2
for i in range(N):
    if sum(a[i])%2!=mod:
        print(-1)
        sys.exit()

if mod==0:
    a=[[ a[i][0]-1 ,a[i][1] ] for i in range(N)]

if mod==0:
    print(32)
    print(1,end=" ")
    for i in range(30): print(2**i, end=" ")
    print(2**30)
else:
    print(32)
    for i in range(30): print(2**i, end=" ")
    print(2**30)

for i in range(N):
    [x,y]=a[i]
    u=bin((x+y+2**31-1)//2)[2:].zfill(31)
    v=bin((x-y+2**31-1)//2)[2:].zfill(31)
    
    if mod==0: s="R"
    else: s=""

    for i in range(30,-1,-1): s=s+cal( int(u[i]),int(v[i]) )
    
    print(s)