n = int(input())
max = -1000000000
min = int(input())
for i in range(1, n):
  r = int(input())
  if max < (r - min):
    max = r - min
  if min > r:
    max = min
print(max)