def fill9(x,u):
    k=x//9
    for i in range(k):
        u[i]=9
    if x%9:
        u[k]=x%9
        return k+1
    else:
        return k
n=input()
n=int(n)
u=[0 for i in range(300//9*150+150)]
k=1
for i in range(n):
    x=input()
    x=int(x)
    t=k-1
    while t>=0:
        if u[t]+9*t<x:
            t=fill9(x,u)
            if t>k:
                k=t
            break
        elif u[t]>=x:
            t+=1
            u[t]+=1
            x-=1
            while u[t]==10:
                u[t]=0
                t+=1
                u[t]+=1
                x+=9
            if t+1>k:
                k=t+1
            for t in range(fill9(x,u),t):
                u[t]=0
            break
        else:
            x-=u[t]
            t-=1
    v=[str(j) for j in u[k-1:-len(u)-1:-1]]
    print(''.join(v))