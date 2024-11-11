n = int(input()) #3
x, y = 0, 0
for i in range(n):
  # m, c = [3, 5]
  # m = 3
  # c = 5
  m, c = [int(i) for i in input().split()]
  # m, c = list(map(int, input().split()))
  if m > c:
    x += 1
  elif m < c:
    y += 1

if x > y:
  print('Mishka')
elif y > x:
  print('Chris')
else:
  print('Friendship is magic!^^')
