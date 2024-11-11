n = int(input())

for i in range(1, 10):
  if n%i == 0:
    s = n/i

if s <= 9:
  print('Yes')
else:
  print('No')