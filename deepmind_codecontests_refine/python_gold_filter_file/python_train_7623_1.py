import sys
sys.setrecursionlimit(11000)

_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__

def go():
    n = int(input())
    if n==2:
        return '1 1'
    # n,l,r = map(int, input().split())
    # a = list(map(int, input().split()))

    e = {i: set() for i in range(1, n + 1)}
    rank = [0] * (n + 1)
    root=-1
    for _ in range(n - 1):
        a, b = map(int, input().split())
        e[a].add(b)
        e[b].add(a)
        rank[a] += 1
        rank[b] += 1
        if rank[a]>1:
            root=a
        if rank[b]>1:
            root=b

    mx = n-1
    for a in range(1,n+1):
        cnt=sum(rank[b]==1 for b in e[a])
        mx-=max(0,cnt-1)

    ev,od = False,False
    que=[root]
    i=0
    dep = [0]*(n+1)
    done = {root}
    while i<len(que):
        v = que[i]
        if len(e[v])==1:
            if dep[v]%2==0:
                ev=True
            if dep[v]%2==1:
                od=True
        for w in e[v]:
            if w not in done:
                que.append(w)
                dep[w]=dep[v]+1
                done.add(w)

        i+=1
    if ev and od:
        mn=3
    else:
        mn=1

    return f'{mn} {mx}'

    #
    # hei = [-1]*(n+1)
    # def dfs(v,par):
    #     if len(e[v])==1:
    #         hei[v]=0
    #     else:
    #         hei[v]=min(dfs(w,v) for w in e[v] if w!=par)+1
    #     return hei[v]
    #
    # dfs(root,-1)
    # # print (hei)
    #
    # kolej = sorted((i for i in range(1,n+1) if rank[i]>1),key=hei.__getitem__)
    # print (kolej)
    #
    # res=0
    # for v in kolej:
    #     if rank[v]
    #

    # que = [i for i in range(1, n + 1) if rank[i] == 1]
    # dep = [0 if rank[i] == 1 else -1 for i in range(0, n + 1)]
    # index = 0
    # while index < len(que):
    #     cur = que[index]
    #     curd = dep[cur]
    #     for b in e[cur]:
    #         if dep[b] < 0:
    #             dep[b] = curd + 1
    #             que.append(b)
    #     index += 1
    # print(dep)
    # kolej = sorted(range(1, n + 1), key=dep.__getitem__)


# x,s = map(int,input().split())
# t = int(input())
t = 1
ans = []
for _ in range(t):
    # print(go())
    ans.append(str(go()))
#
print('\n'.join(ans))
