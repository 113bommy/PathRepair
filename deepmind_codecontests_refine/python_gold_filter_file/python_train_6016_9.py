import itertools
N,M,Q = map(int,input().split())
L = [list(map(int,input().split())) for _ in range(Q)]
data = list(range(1,M+1))
A=list(itertools.combinations_with_replacement(data,N))
max_score = 0

for Ai in A:
  x = 0
  for a,b,c,d in L:
    if Ai[b-1] - Ai[a-1] == c:
      x += d
  max_score = max(max_score,x)

print(max_score)