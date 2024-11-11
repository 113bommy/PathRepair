N,A,B,C=map(int,input().split())
l=[int(input()) for i in range(N)]
inf=10**9
def dfs(d,a,b,c):
    if d==n:#合成完了
        return abs(a-A)+abs(b-B)+abs(c-C)-30 if min(a,b,c)>0 else inf #無からは作れない#0に合成するのにmpは使わないので-30
    ret0=dfs(d+1,a,b,c)#l[d]を使わない
    ret1=dfs(d+1,a+l[d],b,c)+10#l[d]をAに
    ret2=dfs(d+1,a,b+l[d],c)+10#l[d]をBに
    ret3=dfs(d+1,a,b,c+l[d])+10#l[d]をCに
    return min(ret0,ret1,ret2,ret3)
print(dfs(0,0,0,0))