N,M=list(map(int,input().split()))
lst=list(map(int,input().split()))
lst.sort()
if lst[0-M]*4*M>=sum(lst):
  print('Yes')
else:
  print('No')