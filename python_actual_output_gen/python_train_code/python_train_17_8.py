n=int(input())
d=dict()
for i in range(n):
    x,y=map(int,input().split())
    d[x]=y
k=sorted(d.keys())
if len(k)<2:
    print(len(k))
else:
    down=2
    occ=d[k[0]]
    for num in range(1,n-1):
        if k[num]-occ>d[k[num]]:
            down+=1
            occ=k[num]
        elif k[num+1]-k[num]>d[k[num]]:
            down+=1
            occ=k[num]+d[k[num]]
        else:
            occ=k[num]
    print(down)
