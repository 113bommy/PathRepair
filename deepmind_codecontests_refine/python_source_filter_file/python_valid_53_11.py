from collections import defaultdict as df
for _ in range(int(input())):
  n,k=map(int,input().split())
  a=list(map(int,input().split()))
  cnt=0
  b=[]
  for i in range(n):
    b.append([a[i],i])
  b.sort()
  for i in range(1,n):
    if b[i][1]-b[i-1][1]!=1:
      cnt+=1
  if cnt>k:
    print('No')
  else:
    print('Yes')