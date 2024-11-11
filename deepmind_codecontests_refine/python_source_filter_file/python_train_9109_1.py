from sys import stdin,stdout
nmbr = lambda: int(stdin.readline())
lst = lambda: list(map(int,stdin.readline().split()))
def dis(x,y,x1,y1):
    return (x-x1)*(x-x1)+(y-y1)*(y-y1)
for _ in range(1):#nmbr()):
    n,x1,y1,x2,y2=lst()
    ans=float('inf')
    l=[lst() for _ in range(n)]
    for i in range(n):
        sel1=dis(l[i][0],l[i][1],x1,y1)
        sel2=0
        for j in range(n):
            d1,d2=dis(l[j][0],l[j][1],x1,y1),dis(l[j][0],l[j][1],x2,y2)
            if d1<=sel1:continue
            else:sel2=max(sel2,d2)
        ans=min(ans,sel1+sel2)
    for i in range(n):
        sel2=dis(l[i][0],l[i][1],x2,y2)
        sel1=0
        for j in range(n):
            d1,d2=dis(l[j][0],l[j][1],x1,y1),dis(l[j][0],l[j][1],x2,y2)
            if d2<=sel2:continue
            else:sel1=max(sel2,d1)
        ans=min(ans,sel1+sel2)
    print(ans)