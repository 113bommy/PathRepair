n, m = map(int,input().split())
a = list(map(int,input().split()))
a.sort()
total = sum(a)
if total/(4*m) > a[-m]:
  print("No")
else:
  print("Yes")