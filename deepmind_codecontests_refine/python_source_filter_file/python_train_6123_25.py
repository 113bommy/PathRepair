import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**7)
n = int(input())
edge = [[] for i in range(n)]
for i in range(n-1):
    x,y = map(int,input().split())
    edge[x-1].append(y-1)
    edge[y-1].append(x-1)
mod = 10**9+7
p = -1
le = -1
for i in range(n):
    if len(edge[i]) > le:
        p = i
#c[i]:iの子の集合
c = [[] for i in range(n)]
def ch(x,y):
    for e in edge[x]:
        if e == y:
            continue
        c[x].append(e)
        ch(e,x)
ch(p,-1)

#dp[i][k]:iを親とする木の場合の数.kが0ならiは黒,1なら白
dp = [[-1,-1] for i in range(n)]

#dp[x][0]を求める
def bla(x):
    if dp[x][0] != -1:
        return dp[x][0]
    res = 1
    for e in c[x]:
        res = res*whi(e)%mod
    dp[x][0] = res
    return res

#dp[x][1]を求める
def whi(x):
    if dp[x][1] != -1:
        return dp[x][1]
    res = 1
    for e in c[x]:
        res = ( (bla(e)+whi(e))%mod )*res%mod
    dp[x][1] = res
    return res
print(bla(p)+whi(p))