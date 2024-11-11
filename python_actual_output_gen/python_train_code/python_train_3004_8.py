N,M=list(map(int,input().split()))
lst=list(map(int,input().split()))
lst.sort()
if lst[M-1]*4*M>sum(lst):
  print('Yes')
else:
  print('No')