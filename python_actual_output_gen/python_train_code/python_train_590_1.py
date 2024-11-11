x, y = [int(n) for n in input().split()]
if (x < y):
    x, y = y, x
while y > 0:
    x, y = x, x % y
print(x)

