n = int(input())
for i in range(n):
  x1, y1, x2, y2, x3, y3, x4, y4 = [float(j) * 10**5 for j in input().split()]
  if x2 == x1:
    if x4 == x3:
      print("YES")
    else:
      print("NO")
  elif x4 == x3:
    print("NO")
  else:
    print("YES" if (y2 - y1) / (x2 - x1) == (y4 - y3) / (x4 - x3) else "NO")