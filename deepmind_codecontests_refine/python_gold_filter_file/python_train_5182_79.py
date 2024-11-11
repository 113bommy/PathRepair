N, K = map(int,input().split())
P = list(map(int,input().split()))
C = list(map(int,input().split()))
scores = []
for i in range(N):
  pos = P[i]-1
  s = [C[i]]
  j = 1
  while j < K and pos != i:
    s.append(s[-1]+C[pos])
    pos = P[pos]-1
    j += 1
  smax = max(s)
  length = len(s)
  if length < K and s[-1] > 0:
    if K%length != 0:
      smod = s[:K%length]
      smodmax = max(smod)
    else:
      smodmax = 0
    scores.append(max(s[-1] * ((K//length)-1) + smax, s[-1] * (K//length), s[-1] * (K//length) + smodmax))
  else:
    scores.append(smax)
print(max(scores))