n = int(input())
a = list(map(int, input().split()))

n2 = 0
n4 = 0

for ai in a:
  if ai % 4 == 2:
    n2 += 1
  if ai % 4 == 0:
    n4 += 1

if n2 == 0 and n4:
  n2 += 1
if n2 + n4 * 2 >= n:
  print('Yes')
else:
  print('No')
