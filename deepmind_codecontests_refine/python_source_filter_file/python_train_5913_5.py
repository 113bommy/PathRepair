from collections import defaultdict
N, K = map(int, input().split())
A = [(int(c)%K)-1 for c in input().split()]
B = [0]
for c in A:
  B += [B[-1]+c]
dic = defaultdict(int)
ldic = defaultdict(int)
for i in range(min(K,N)):
  c = B[i]
  dic[c%K] += 1
ans = 0
#print(dic)
for i in range(1,N+1):
  x = B[i-1]
  ldic[x%K] += 1
  ans += dic[x%K]-ldic[x%K]
  if K+i-1<=N:
    dic[B[K+i-1]%K] += 1
  """
  print('###############')
  print(i,x, ans)
  print(dic)
  print(ldic)
  """
print(ans)