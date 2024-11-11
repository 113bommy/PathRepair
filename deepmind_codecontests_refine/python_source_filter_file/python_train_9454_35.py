from itertools import combinations
n = int(input())
k = 0
for i in range(n):
  if i * (i - 1) == 2 * n:
    k = i
    break
if k:
  ans = [[k-1] for _ in range(n)]
  i = 1
  for a, b in combinations(range(n), 2):
    ans[a].append(i)
    ans[b].append(i)
    i += 1
  print('Yes')
  print(k)
  for ansi in ans:
    print(' '.join(list(map(str, ansi))))
else:
  print('No')