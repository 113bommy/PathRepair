n,m = map(int,input().split())
l = [0 for i in range(n+1)]
for i in range(m):
    x,y,z = map(int,input().split())
    if l[x]+l[y]+l[z]==0:
        l[x]=1
        l[y]=2
        l[z]=3
    else:
        if l[x]:
            if l[x]==1:
                l[y]=2
                l[z]=3
            elif l[x]==2:
                l[y]=1
                l[z]=3
            else:
                l[y]=1
                l[z]=2
        elif l[y]:
            if l[y]==1:
                l[x]=2
                l[z]=3
            elif l[y]==2:
                l[x]=1
                l[z]=3
            else:
                l[x]=1
                l[z]=2
        else:
            if l[z]==1:
                l[x]=2
                l[y]=3
            elif l[z]==2:
                l[x]=1
                l[y]=3
            else:
                l[x]=1
                l[y]=2
for i in range(1,len(l)):
    print(l[i],end=' ')