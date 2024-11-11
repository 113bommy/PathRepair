n,k=map(int,input().split())
a=list(map(int,input().split()))
z=[0]*81
kz,ans=0,0
for i in range(n):
    if z[a[i]]: continue
    ans+=1
    if k>kz:
        z[a[i]]=1; kz+=1
    else:
        h=-1
        for j in range(n):
            if z[j]:
                m=n+1
                for p in range(i,n):
                    if j==a[p]:
                        m=p;
                        break
                if m>h:
                    h=m;
                    t=j
        z[t]=0
        z[a[i]]=1
print(ans)
