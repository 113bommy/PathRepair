n,A,B,C = map(int,input().split())
l = list(int(input())for _ in range(n))
def dfs(depth,a,b,c):
    if depth == n:
        return abs(a-A)+abs(b-B)+abs(c-C)-30  if min(a,b,c) >0 else 10**9
    x = dfs(depth+1,a,b,c)
    y = dfs(depth+1,a+l[depth],b,c) +10
    z = dfs(depth+1,a,b+l[depth],c) +10
    w = dfs(depth+1,a,b,c+l[depth]) +10
    return min(x,y,z,w)
print(dfs(0,0,0,0))
    
        