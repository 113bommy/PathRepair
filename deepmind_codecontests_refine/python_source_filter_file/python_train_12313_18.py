a, x, y = [int(i) for i in input().split()]

if abs(x) >= a or y <= 0 or y % a == 0:
    print(-1)
elif y < 2 * a:
    if abs(x) < a / 2 and y < a:
        print(1)
    elif abs(x) < a / 2:
        print(2)
    else:
        print(-1)
elif y // a % 2 == 0: # 2-square case
    left_square = int(y // a * 1.5)
    if x < 0:
        print(left_square)
    elif x > 0:
        print(left_square + 1)
    else:
        print(-1)
elif y // a % 2 == 1: # 1-square case
    square = int((y // a) / 2 + 1) + (y // a)
    if abs(x) < a:
        print(square)
    else:
        print(-1)
else:
    print(-1)