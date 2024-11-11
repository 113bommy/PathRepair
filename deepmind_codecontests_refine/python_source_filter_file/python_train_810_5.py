N, A, B, C = map(int, input().split())
ls = [int(input()) for i in range(N)]

def dfs(cur, a, b, c):
  if cur==N:
    return abs(A-a)+abs(B-b)+abs(C-c)-30 if min(a,b,c)>0 else 10**9
  ret0 = dfs(cur+1, a+ls[cur], b, c)
  ret1 = dfs(cur+1, a, b+ls[cur], c)
  ret2 = dfs(cur+1, a, b, c+ls[cur])
  ret3 = dfs(cur+1, a, b, c)
  return min(ret0, ret1, ret2, ret3)
print(dfs(0,0,0,0))