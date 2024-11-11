import sys
from collections import deque

input=sys.stdin.readline

t=1
t=int(input())
for _ in range(t):
    n=int(input())
    val=set([0,2*10**5+1])
    seg=[(0,2*10**5+1)]
    for i in range(n):
        l,r=map(int,input().split())
        val.add(l)
        val.add(r)
        seg.append((l,r))
    val=list(val)
    val.sort()
    comp={i:e+1 for e,i in enumerate(val)}
    for i in range(n+1):
        l,r=seg[i]
        seg[i]=(comp[l],comp[r])

    deg=[0]*(n+1)
    out=[[] for i in range(n+1)]
    for i in range(n+1):
        for j in range(i+1,n+1):
            l,r=seg[i]
            L,R=seg[j]
            if L<=l and r<=R:
                out[j].append(i)
                deg[i]+=1
            elif l<=L and R<=r:
                out[i].append(j)
                deg[j]+=1

    ans=[0]
    deq=deque(ans)

    while deq:
        v=deq.popleft()
        for nv in out[v]:
            deg[nv]-=1
            if deg[nv]==0:
                deq.append(nv)
                ans.append(nv)

    dp=[0]*(n+1)

    def solve(v):
        query=[[] for i in range(2*n+3)]
        for nv in out[v]:
            l,r=seg[nv]
            query[r].append((l,dp[nv]))
        subdp=[0]*(2*n+3)
        for i in range(1,2*n+3):
            res=subdp[i-1]
            for l,val in query[i]:
                test=subdp[l-1]+val
                res=max(test,res)
            subdp[i]=res

        dp[v]=subdp[-1]+1

    for v in ans[::-1]:
        solve(v)

    print(dp[0]-1)
