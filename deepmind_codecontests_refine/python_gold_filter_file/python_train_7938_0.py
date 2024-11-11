s = input()

n, m, x, y = [int(i) for i in s.split(" ")]
print(x,y)

tx, ty = 1, y
if (tx, ty) != (x, y):
    print(tx, ty)

for cs in range(1, n+1, 2):
    for ys in range(1, m+1):
        if (cs, ys) != (tx, ty) and (cs, ys) != (x, y):
            print(cs, ys)
    cs += 1
    if cs > n:
        continue
    for ys in range(m, 0, -1):
        if (cs, ys) != (tx, ty) and (cs, ys) != (x, y):
            print(cs, ys)
