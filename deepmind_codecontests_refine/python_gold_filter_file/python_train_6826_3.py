points = {}
n = int(input())
for _ in range(n):
  a = input().split()
  points[a[0]] = int(a[1]) * 100 - int(a[2]) * 50 + sum(map(int, a[3:]))
ans, max_point = '', -1000000
for handle, point in points.items():
  if point > max_point:
    max_point = point
    ans = handle
print(ans)
