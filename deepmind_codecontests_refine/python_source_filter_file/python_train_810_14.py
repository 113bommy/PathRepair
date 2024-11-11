n,a,b,c = map(int, input().split())
l = [int(input()) for _ in range(n)]
def dfs(k,p,q,r):
  if k == n:
    if min(a,b,c) > 0:
      return abs(p-a)+abs(q-b)+abs(r-c)-30
    else:
      return 10**7
  t1 = dfs(k+1,p,q,r)
  t2 = dfs(k+1,p+l[k],q,r)+10
  t3 = dfs(k+1,p,q+l[k],r)+10
  t4 = dfs(k+1,p,q,r+l[k])+10
  return min(t1,t2,t3,t4)

print(dfs(0,0,0,0))