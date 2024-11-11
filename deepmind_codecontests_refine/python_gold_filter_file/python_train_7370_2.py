n=int(input())
l=[]
if n==1:
    print(1)
    exit()
else:
    for i in range(n):
        x,y=map(int,input().split())
        l.append((x,y))
    x={}
    for i in l:
        for j in l:
            if i!=j:
                t=(i[0]-j[0],i[1]-j[1])
                if t in x:
                    x[t]+=1
                else:
                    x[t]=1
    print(n-max(x.values()))