N,M=list(map(int,input().split()))
lst=list(map(int,input().split()))
lst.sort()
if lst[1-M]*4*M>=sum(lst):
  print('Yes')
else:
  print('No')