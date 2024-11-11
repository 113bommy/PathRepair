n,k = map(int,input().split())
a = sorted(list(map(int,input().split())))
a2 = [-1] + a
if k==n or a2[k+1]-a2[k]:
  print(a2[k])
else:
  print (-1)