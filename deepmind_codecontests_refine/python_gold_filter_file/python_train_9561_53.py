from itertools import combinations

N,K=map(int,input().split())
o=[tuple(map(int,input().split())) for _ in range(N)]
ans=float("inf")

for i,j in combinations(o,2):
    x1,y1=i
    x2,y2=j
    xmax,xmin=max(x1,x2),min(x1,x2)

    for k,l in combinations(o,2):
        x3,y3=k
        x4,y4=l
        ymax,ymin=max(y3,y4),min(y3,y4)

        v=0
        for m in o:
            x5,y5=m
            if xmin<=x5<=xmax and ymin<=y5<=ymax:
                v+=1
        
        if v>=K:
            ans=min(ans,(ymax-ymin)*(xmax-xmin))


print(ans)