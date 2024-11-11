import sys

input=sys.stdin.readline

sys.setrecursionlimit(100000)

N=int(input())
edge={i:[] for i in range(1,N+1)}
for i in range(0,N-1):
    a,b=map(int,input().split())
    edge[a].append(b)
    edge[b].append(a)
mod=10**9+7

parent={i:0 for i in range(1,N+1)}

q=set([1])
sub=set([])
while q:
    while q:
        x=q.pop()
        for p in edge[x]:
            if p!=1 and parent[p]==0:
                parent[p]=x
                sub.add(p)

        if not q:
            q=sub
            sub=set([])
            break


def dfs(num):
    if len(edge[num])==1 and num!=1:
        return (1,1)

    WHITE=1
    BLACK=1
    for i in edge[num]:
        if i!=parent[num]:
            s,t=dfs(i)
            WHITE=(WHITE*(s+t))%mod
            BLACK=(BLACK*s)%mod

    return (WHITE,BLACK)

w,b=dfs(1)
print((w+b)%mod)