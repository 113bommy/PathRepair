N, K, S=map(int, input().split())
if S==10**9:
  ans=[10**9]*K+[10**9]*(N-K)
  print(*ans)
else:
  ans=[S]*K+[S+1]*(N-K)
  print(*ans)