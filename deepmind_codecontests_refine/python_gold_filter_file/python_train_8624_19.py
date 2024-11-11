import itertools
n = int(input())
s = input()
t = [''] * n
for p in itertools.product(['o', 'x'], repeat=2):
  t[-1] = p[0]
  t[0] = p[1]
  for i in range(1, n - 1):
    if (t[i - 2] + t[i - 1] + s[i - 1]).count('x') % 2 == 0:
      t[i] = 'o'
    else:
      t[i] = 'x'
  if (t[-3] + t[-2] + t[-1] + s[-2]).count('x') % 2 == 0 and (t[-2] + t[-1] + t[0] + s[-1]).count('x') % 2 == 0:
    ans = []
    for c in t:
      if c == 'o':
        ans.append('S')
      else:
        ans.append('W')
    print(*ans, sep='')
    break
else:
  print(-1)
