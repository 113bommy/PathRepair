n,m=map(int,input().split())
b=[int(a) for a in input().split()]
if sum(b)<n:print(-1)
else:
    s=n+1;r=[-1]*m;i=0
    for j in b[::-1]:
        s=max(s-j,m-i)
        if s+j-1>n:print(-1);break
        r[i]=s;i+=1
    else:print(*r[::-1])
