a, b, c, d = list(map(int, input().split(" ")))
x1 = (3 * a) // 10
x2 = (3 * b) // 10
y1 = a - (a // 250) * c
y2 = b - (b // 250) * d
z1 = max(x1, y1)
z2 = max(x2, y2)
if (a % 250 == 0 and b % 250 == 0):
    if (z1 > z2):
        print("MIsha")
    elif (z1 == z2):
        print("Tie")
    else:
        print("Vasya")
exit()
