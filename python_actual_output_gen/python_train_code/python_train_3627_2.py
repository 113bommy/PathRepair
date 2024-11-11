(x, y) = input().split(" ")
x = int(x)
y = int(y)

k = 1 if -(y // x) > 0 else  -1

b = y - k * x

print(b)

tr_x = -b // k
tr_y = b

if tr_x < 0:
    print(tr_x, 0, 0, tr_y)
else:
    print(0, tr_y, tr_x, 0)
