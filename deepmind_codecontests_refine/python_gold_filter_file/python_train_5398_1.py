import copy

N,K = map(int,input().split())
A = list(map(int,input().split()))

ans = [10 ** 12 for i in range(2 ** (N - 1))]
seen = 1  #[[A[j] for j in range(i,N) if A[j] > A[i]] for i in range(0,N)]

for i in range(2 ** (N - 1)):
  AA = copy.deepcopy(A)
  cost = 0
  s = str(bin(i))[2:]
  if s.count("1") >= K:
    continue
    
  for j in range(N - 1):
    m = max(AA[:j + 1])
    a = AA[j + 1]
    if ((i >> j) & 1) and a <= m:
      cost += (m - a + 1)
      AA[j + 1] = m + 1
  
  if len([AA[i] for i in range(1,N) if AA[i] > max(AA[:i])]) >= K - 1:
    ans[i] = cost
    #print(AA,bin(i),cost)
    
print(min(ans))

