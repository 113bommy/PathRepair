from collections import defaultdict
N, *A = map(int, open('0').read().split())
ans = 0
A.sort()
dic = defaultdict(list)
for i, a in enumerate(A):
  dic[a] += [i]
for i in range(N-1,-1,-1):
  a = A[i]
  if dic[a]==[]:
    continue
  dic[a].pop()
  k = 1
  while k<=a:
    k *= 2
  n = k-a
  if dic[n]!=[]:
    dic[n].pop()
    ans += 1
print(ans)
