a,b=map(int,input().split())
l,r=0,a;ans=1
z=[0]*(a+1)
for _ in " "*b:
    u,v=sorted(map(int,input().split()))
    if z[u]==2 or z[v]==1:ans=0
    elif z[u]!=0 and z[v]!=0 and z[u]==z[v]:ans=0
    else:
        z[u]=1;z[v]=2
        if u>=r:ans=0
        if v<=l:ans=0
        l=max(l,u);r=min(r,v)
if ans==0:print(ans)
elif l==0 and r==b:print(b-2)
else:print(r-l)