import sys

sys.setrecursionlimit(10 ** 6)
int1 = lambda x: int(x) - 1
p2D = lambda x: print(*x, sep="\n")
def II(): return int(sys.stdin.readline())
def MI(): return map(int, sys.stdin.readline().split())
def MI1(): return map(int1, sys.stdin.readline().split())
def LI(): return list(map(int, sys.stdin.readline().split()))
def LLI(rows_number): return [LI() for _ in range(rows_number)]
def SI(): return sys.stdin.readline()[:-1]

def main():
    def imp():
        print("No")
        exit()

    n=II()
    to=[[] for _ in range(n)]
    for _ in range(n-1):
        u,v=MI1()
        to[u].append(v)
        to[v].append(u)
    k=II()
    pp=[-1]*n
    for _ in range(k):
        v,p=MI()
        pp[v-1]=p

    dp=[[-1,-1,-1] for _ in range(n)]

    def dfs(u=0,pu=-1):
        par=mn=mx=-1
        for v in to[u]:
            if v==pu:continue
            dfs(v,u)
            pv, mnv, mxv = dp[v]
            if pv==-1:continue
            if par==-1:par,mn,mx=1-pv,mnv-1,mxv+1
            else:
                if par^pv==0:imp()
                mn=max(mn,mnv-1)
                mx=min(mx,mxv+1)
                if mn>mx:imp()
        p=pp[u]
        if p==-1:dp[u]=[par,mn,mx]
        elif par!=-1 and (p&1!=par or p<mn or p>mx):imp()
        else:dp[u]=[p&1,p,p]

    dfs()
    #print(dp)
    for p0 in range(dp[0][1],dp[0][2]+1):
        if p0&1==dp[0][0]:
            pp[0]=p0
            break
    else:imp()

    def dfs2(u=0,pu=-1):
        if pp[u]==-1:
            p=pp[pu]
            for d in [1,-1]:
                if dp[u][1]==-1 or dp[u][1]<=p+d<=dp[u][2]:
                    pp[u]=p+d
                    break
        for v in to[u]:
            if v==pu:continue
            dfs2(v,u)

    dfs2()
    #print(pp)
    print("Yes")
    for p in pp:print(p)

main()