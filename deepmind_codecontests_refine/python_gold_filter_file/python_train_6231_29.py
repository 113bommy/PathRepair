n,m=map(int,input().split());a,b=[list(map(int,input().split()))for i in range(m)],[float("INF")]*(n+1);b[1]=0
for i in range(1,n+1):
    for s,t,u in a:
        if b[t]>b[s]-u:
            b[t]=b[s]-u
            if i==n and t==n:print("inf");exit()
print(-b[-1])