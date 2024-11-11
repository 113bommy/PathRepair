def nod(a, b):
    while b != 0:
        a, b = b, a % b
    return a


for _ in range(int(input())):
    angle = int(input())
    d = nod(180, angle)
    n = 180 // d
    x = angle // d
    if n - x < 2:
        n *= 2
        x = (angle * n) // 180
    print(x if n - x >= 2 else -1)
