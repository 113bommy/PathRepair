a = list(map(int, input().split()))
w1 = 0
w2 = 0
draw = 0
for i in range(1, 7):
    if abs(a[0] - i) > abs(a[1] - i):
        w1 += 1
    elif abs(a[0] - i) == abs(a[1] - i):
        draw += 1
    else:
        w2 += 1
print(w1, draw, w2)

