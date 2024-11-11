a,b=map(int,input().split())
x,y=map(int,input().split())
ans=0
for _ in " "*int(input()):
    u,v=map(int,input().split())
    if u==0 :
        t=0
        if v<0:
            t=(y-1)//(-v)
        else:t=(b-y)//v
        y+=v*t
        ans+=t
    elif v==0:
        t=0
        if u<0:t=(x-1)//(-u)
        else:t=(a-x)//u
        x+=t*u
        ans+=t
    else:
        t,t1=0,0
        if u<0:
            t=(x-1)//(-u)
        else:
            t=(a-x)//u
        if v<0:
            t1=(y-1)//(-v)
        else:t1=(b-y)//v
        t=min(t,t1)
        ans+=t
        y+=t*v;x+=t*u
print(ans)