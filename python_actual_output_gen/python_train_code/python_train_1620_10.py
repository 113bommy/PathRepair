x, y = map(int, input().split())
sum = 0
if x < 4:
  sum += (4-x) * 100000
if y < 4:
  sum += (4-y) * 100000
if x == 1 and y == 1:
  sum += 4 * 100000
  print(sum)