n = int(input())
mx = 0
for i in range(n):
  s = input().split()
  x, y = int(s[0]), int(s[1])
  c = y + x
  if c>mx:
    mx = c

print(mx)