n,m=map(int,input().split())
l=list(map(int,input().split()))
l.sort()
d={}
for i in l:
    if i not in d:
        d[i]=1
    else:
        d[i]+=1
e=list(d.keys())
e.append(0)
ans=0
r=1000000000000000
for i in range(0,200001):
    if i in d:
        x=d[i]
    else:
        x=0
    if(x>=m):
        r=0
        break
    ans=0
    for j in l:
        if(j==i):
            continue
        else:
            f=0
            while(j>=i):
                if(j==i or j==0):
                    x+=1
                    ans+=f
                    break
                j//=2
                f+=1
        if(x>=m):
            r=min(ans,r)
            break
print(r)
    