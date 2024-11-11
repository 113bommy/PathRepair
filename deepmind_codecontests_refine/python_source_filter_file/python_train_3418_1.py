ar = [[int(i) for i in input().split()] for j in range(3)]

if ar[0][0] + ar[1][1] + ar[2][2] == ar[0][1] + ar[1][2] + ar[2][0] == ar[0][3] + ar[1][0] + ar[2][1]:
  print("Yes")
else:
  print("No")