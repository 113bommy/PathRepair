n,k=map(int,input().split())
v=[int(i) for i in input().split()]
r=min(n,k)
ans=0
for a in range(r+1):
    for b in range(r-a+1):
        if b>=1:
            q=v[:a]+v[-b:]
        else:
            q=v[:a]
        t=r-a-b
        m=0
        for i in sorted(q):
            if i<0 and t>0:
                m+=abs(i)
                t-=1
        ans=max(ans,m+sum(q))
print(ans)
        