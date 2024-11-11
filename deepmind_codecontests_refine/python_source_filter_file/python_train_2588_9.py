from collections import *
h,w,n = map(int,input().split())
dic = defaultdict(int)
for _ in range(n):
  a,b = map(int,input().split())
  for i in range(9):
    dic[a - i //3,b - i % 3] += 1
ans =[0]*(n+1)
for i, j in dic:
  ans[dic[i,j]] += h-1 > i > 0 < j < w -1
ans[0] = (h -2)*(w-2) - sum(ans)
for item in ans:
  print(item)