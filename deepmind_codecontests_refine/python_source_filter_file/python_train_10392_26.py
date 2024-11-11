import sys
import itertools
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]
c = ['R', 'U', 'L', 'D']
n = int(input())
x = []
y = []
for i in range(n):
  xi, yi = map(int, input().split())
  x.append(xi)
  y.append(yi)
parity = None
for i in range(n):
  if i == 0:
    parity = (x[i] + y[i]) % 2
  elif (x[i] + y[i]) % 2 != parity:
    print(-1)
    sys.exit()
print(40)
d = []
for i in range(20):
  d.append(3**i)
  d.append(3**i)
d[1] += parity
print(*d)
d = [1] * 40
d[1] += parity
for i in range(n):
  for m in range(20):
    for j, k in itertools.product(range(4), range(4)):
      xnew = x[i] - (d[2*m] * dx[j] + d[2*m+1] * dx[k])
      ynew = y[i] - (d[2*m+1] * dy[j] + d[2*m+1] * dy[k])
      if xnew % 3 == 0 and ynew % 3 == 0:
        x[i] = xnew // 3
        y[i] = ynew // 3
        print(c[j] + c[k], end='')
        break
  print('')