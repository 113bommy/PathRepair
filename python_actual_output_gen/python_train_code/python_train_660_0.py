n = int(input())
a = list(map(int, input().split()))
l, r, c = 0, 0, 0
while r < n:
  if l < r and a[r] > 1:
    x = min(a[l], a[r] // 2)
    c += x
    a[l] -= x
    a[r] -= 2 * x
  else:
    x = a[r] // 3
    c += x
    a[r] -= x
    r += 1
  while r < n and a[r] == 0: r += 1
  while l < r and a[l] == 0: l += 1
print(c)
