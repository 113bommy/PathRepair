from bisect import bisect_left
INF = 10**18
A, B, Q = map(int, input().split())
als = [int(input()) for i in range(A)]
bls = [int(input()) for i in range(B)]
als = [-INF]+als+[INF]
bls = [-INF]+bls+[INF]

for i in range(Q):
  x = int(input())
  ai = bisect_left(x,als)
  bi = bisect_left(x,bls)
  res = INF
  for S in [als[ai], als[ai-1]]:
    for T in [bls[bi], bls[bi-1]]:
      d1, d2 = abs(S-x)+abs(T-S), abs(T-x)+abs(S-T)
      res = min(res,d1,d2)
  print(res)