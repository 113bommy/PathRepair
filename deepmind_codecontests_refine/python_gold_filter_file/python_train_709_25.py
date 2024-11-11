n = int(input())
a = list(map(int, input().split()))
a0, a1, a2 = 0, 0, 0
for i in a:
  if i % 2 == 1:
    a0 += 1
  elif i % 4 == 2:
    a1 = 1
  else:
    a2 += 1
if a0 + a1 <= a2 + 1:
  print('Yes')
else:
  print('No')
