n,m=map(int,input().split())
l=list(map(int,input().split()))
l.sort()
if l[0-m]>=sum(l)/(4*m):
  print("Yes")
else:
  print("No")