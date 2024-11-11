n = int(input())
a = list(map(int, input().split()))

n2 = 0
n4 = 0

for ai in a:
  if ai % 4 == 2:
    n2 += 1
  if ai % 4 == 0:
    n4 += 1

if not n2 and n4:
  n2 += l
if n2 + n4 * 2 >= n:
  print('Yes')
else:
  print('No')
