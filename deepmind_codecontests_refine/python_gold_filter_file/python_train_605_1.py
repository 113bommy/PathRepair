N=int(input())
P=list(map(int, input().split()))
X=[0]+list(map(int, input().split()))
ko=[[] for _ in range(N+1)]
for i, p in enumerate(P, 2):
  ko[p].append(i)
  
def f(p):
  n=len(ko[p])
  if n==0:
    return X[p], 0
  
  dp=[[float('inf')]*5001 for _ in range(n+1)]
  dp[0][0]=0
  for i, c in enumerate(ko[p], 1):
    a, b=f(c)
    for j in range(a, 5001):
      dp[i][j]=min(dp[i][j], dp[i-1][j-a]+b)
    for j in range(b, 5001):
      dp[i][j]=min(dp[i][j], dp[i-1][j-b]+a)
      
  out=min(dp[-1][:X[p]+1])
  if out==float('inf'):
    print('IMPOSSIBLE')
    exit()
  elif out>X[p]:
    return out, X[p]
  else:
    return X[p], out
  
print('POSSIBLE') if min(f(1))<=X[1] else print('IMPOSSIBLE')