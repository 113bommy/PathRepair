from math import gcd
n = int(input())
a = list(map(int, input().split()))
max_a = max(a)
cnt_a = [0] * (max_a + 1)
for ai in a:
  cnt_a[ai] += 1
ans = 'pairwise'
for i in range(2, max_a + 1):
  cnt = 0
  for j in range(i, max_a + 1, i):
    cnt += cnt_a[j]
  if cnt > 1:
    ans = 'setwise'
g = 0
for ai in a:
  g = gcd(g, ai)

if ans == 'pairwise':
  print(ans, 'coprime')
elif ans == 'setwise' and g == 1:
  print(ans, 'coprime')
else:
  print('not coprime')