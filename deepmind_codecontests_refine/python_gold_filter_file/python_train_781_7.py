n,k,q=map(int,input().split())
z=[0]+list(map(int,input().split()))
p=[]
for i in range(q):
    u,v=map(int,input().split())
    if (u==1):
        p+=[v]
        if (len(p)>k):
            r=10000000000000000000;f=0
            for j in range(len(p)):
                if (z[p[j]]<r):r=z[p[j]];f=p[j]
            p.remove(f)
    else:
        if v in p:print("YES")
        else:print("NO")