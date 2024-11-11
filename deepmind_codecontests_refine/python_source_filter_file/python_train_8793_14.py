import sys
lst = [int(n) for n in sys.stdin.readline().split()]
x = lst[0]
y = lst[1]

steps = 0
while y != x:
    if y < x:
        steps += x - y
        break
    if y % 2 == 1:
        y += 1
    else:
        y /= 2
    steps += 1
print(steps)