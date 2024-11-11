n,m = map(int,input().split())
l = list(map(int,input().split()))
l.sort(reverse=True)
if l[m-1] < (sum(l)/4)/m:
  print('No')
else:
  print('Yes')