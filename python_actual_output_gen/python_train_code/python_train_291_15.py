n,a,b,c=map(int,input().split())
banboo = [int(input()) for i in range(n)]

def dfs(num,A,B,C):
    if num == n:
        return abs(A-a)+abs(B-b)+abs(C-c)-30 if min(A,B,C)>0 else float("inf")
    v1 = dfs(num+1,A,B,C)
    v2 = dfs(num+1,A+banboo[num],B,C) + 10
    v3 = dfs(num+1,A,B+banboo[num],C) + 10
    v4 = dfs(num+1,A,B,C+banboo[num]) + 10
    return min(v1,v2,v3,v4)
dfs(0,0,0,0)