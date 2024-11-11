from sys import stdin, stdout
from decimal import Decimal

n, t1, t2, k = map(Decimal, stdin.readline().split())
challengers = []

for i in range(int(n)):
    a, b = map(Decimal, stdin.readline().split())
    f, s = (a * t1) * (1 - k / 100) + b * t2, (b * t1) * (1 - k / 100) + a * t2
    challengers.append((max(f, s), i))

challengers.sort(key = lambda x: (x[0], n - x[1]), reverse = True)
for i in range(int(n)):
    stdout.write(str(challengers[i][1]) + ' ' + str('%.2f'%challengers[i][0]) + '\n')