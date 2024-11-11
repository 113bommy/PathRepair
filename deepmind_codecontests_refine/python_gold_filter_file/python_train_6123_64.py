
import sys
sys.setrecursionlimit(100005)
mod=1000000007
# https://ikatakos.com/pot/programming_algorithm/contest_history/atcoder/2019/0106_educational_dp_2

def dfs(v,a):
    w=b=1
    for u in links[v]:
        if u==a:
            continue
        cw,cb=dfs(u,v)
        w*=cw+cb
        b*=cw
        w%=mod
        b%=mod
    return w,b


n=int(input())
links=[set() for i in range(n)]

for line in sys.stdin.readlines():
    x,y=map(int, line.split())
    x-=1
    y-=1
    links[x].add(y)
    links[y].add(x)

print(sum(dfs(0,None))%mod)