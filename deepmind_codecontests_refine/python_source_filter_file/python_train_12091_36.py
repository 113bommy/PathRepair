n,m,k = map(int,input().split())
a = list(map(int,input().split()))
a.sort()
if m <= k:
  print(max(a)*m)
else:
  st = a[-1]*k+a[-2]
  print(st*(m//(k+1)+a[-1]*m%(k+1)))