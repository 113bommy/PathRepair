N, M, *X = map(int, open(0).read().split())
A = []
for a in zip(*[iter(X)]*M):
  A.append(a)
log = set(range(1,M+1))
ans = []
while log:
  dic = {}
  for i in range(N):
    for j in range(M):
      if A[i][j] in log:
        dic[A[i][j]] = dic.get(A[i][j],0)+1
        break
  ans.append(max(dic.values()))
  c = max(dic.keys(),key=lambda x:dic[x])
  log.remove(c)
print(min(ans))