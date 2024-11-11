N, x = map(int, input().split())
A = list(map(int, input().split()))
INF = (1<<32)-1
cum = [[INF]*N for _ in range(N)]
for i in range(N):
  for j in range(i,N):
    cum[i][j] = min(cum[i][j-1],A[j])
ans = INF
for k in range(N):
  score = 0
  for j in range(N):
    if j-k>=0:
      score += cum[j-k][j]
    else:
      score += min(cum[0][j],cum[(j-k)%N][-1])
  ans = min(ans, k*x+score)
print(ans)