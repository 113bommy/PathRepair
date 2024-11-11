a = [list(map(int,input().split())) for i in range(3)]
if a[0][0]-a[1][0] == a[0][1]-a[1][1] == a[0][2]-a[1][2] and a[1][0]-a[2][0] == a[1][1]-a[2][1] == a[1][2] == a[2][2]:
  print("Yes")
else:
  print("No")