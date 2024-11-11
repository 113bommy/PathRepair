T1, T2 = map(int, input().split())
A1, A2 = map(int, input().split())
B1, B2 = map(int, input().split())

C1 = A1 - B1
C2 = A2 - B2
if C1 > 0:
    C1, C2 = -C1, -C2

x1 = C1 * T1 + C2 * T2
x2 = x1 + C1 * T1

if x1 == 0:
    print('inifinity')
elif x1 < 0:
    print(0)
else:
    if 0 < x2:
        count = 1
    elif 0 == x2:
        count = 2
    else:
        n = (-x2 + x1 - 1) // x1
        count = 1 + 2 * n
        if x2 % x1 == 0:
            count += 1
    print(count)