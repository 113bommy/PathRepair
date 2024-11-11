x, y = map(int, input().split())
z = [300000, 20000, 100000, 0]
if x > 3: x = 4
if y > 3: y = 4
if x == y == 1:
    print(1000000)
else:
    print(z[~-x] + z[~-y])
