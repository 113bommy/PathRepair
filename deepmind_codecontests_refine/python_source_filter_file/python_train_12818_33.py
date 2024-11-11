from math import ceil

n, x, y = map(int, input().split())
a = [*map(int, input().split())]

t = 0

for i in a:
    if i < x:
        t += 1

if x > y:
    print(n)
else:
    print(ceil(t / 2))

