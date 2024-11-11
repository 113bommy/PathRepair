import math

t = int(input())
for _ in range(t):
    n = int(input())
    s = list(map(int, input().split()))
    f = 0
    for i in range(n - 1):
      if s[i + 1] - s[i] >= 2:
        print('YES')
        print(i + 1, i + 2)
        f = 1
        break
    if f == 0:
      print('NO')


