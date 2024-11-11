N,K = map(int,input().split())
cc = list(map(int,input().split()))
memo = []
aa = ['.']*N
a = 1
while aa[a-1] == '.':
  memo.append(a)
  aa[a-1] = 'v'
  a = cc[a-1]
if len(memo)>K:
  print(aa[K])
else:
  b = memo.index(a)
  m = len(memo)-b
  mm = (K-b) % m
  del memo[:b]
  print(memo[mm])