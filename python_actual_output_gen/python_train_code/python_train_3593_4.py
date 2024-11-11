a, b = map(int, input().split())
if a == b: print('infinity')
elif a < b: print(0)
else:
    s, a = 1, a - b
    y = int(a ** 0.5)
    for x in range(2, y):
        if a % x == 0:
            if x > b: s += 1
            if a > b * x: s += 1
    if y > b and y * y == a: s += 1
    print(s)