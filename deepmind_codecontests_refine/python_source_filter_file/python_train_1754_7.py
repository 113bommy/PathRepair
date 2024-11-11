n,a,b,c,d = map(int, input().split())
for i in range(n):
  pi = i
  mi = n - i
  if a + c * pi - d * mi <= b <= a + d * pi - c * mi:
    print("YES")
    break
else:
  print("NO")