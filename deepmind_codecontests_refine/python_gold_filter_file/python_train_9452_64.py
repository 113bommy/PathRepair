def main():
    def dfs(edge,s):
        use={s}
        q=[s]
        while q:
            v=q.pop()
            for w in edge[v]:
                if w in use:continue
                use.add(w)
                q.append(w)
        return use
    n,m,p,*t=map(int,open(0).read().split())
    edge=[[]for _ in range(n)]
    edge_rev=[[]for _ in range(n)]
    e=[]
    for a,b,c in zip(t[::3],t[1::3],t[2::3]):
        edge[a-1].append(b-1)
        edge_rev[b-1].append(a-1)
        e.append((a-1,b-1,p-c))
    use=dfs(edge,0)&dfs(edge_rev,n-1)
    e=[(a,b,c)for a,b,c in e if a in use and b in use]
    INF=10**18
    d=[0]+[INF]*(n-1)
    for _ in range(n):
        f=False
        for a,b,c in e:
            cost=d[a]+c
            if cost<d[b]:
                d[b]=cost
                f=True
        if not f:break
    else:
        print(-1)
        exit()
    print(max(-d[-1],0))
main()