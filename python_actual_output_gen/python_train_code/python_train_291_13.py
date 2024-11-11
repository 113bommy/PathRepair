N, A, B, C = map(int,input().split())
l = [int(input()) for _ in range(N)]

def dfs(x, a, b, c):
  if x == N:
    if min(a, b, c) >= 30:
      return abs(a-A)+abs(b-B)+abs(c-C)-30
    else:
      return float("inf")
  
  ret0 = dfs(x+1, a, b, c)
  ret1 = dfs(x+1, a+l[x], b, c)+10
  ret2 = dfs(x+1, a, b+l[x], c)+10
  ret3 = dfs(x+1, a, b, c+l[x])+10
  return min(ret0, ret1, ret2, ret3)

print(dfs(0, 0, 0, 0))