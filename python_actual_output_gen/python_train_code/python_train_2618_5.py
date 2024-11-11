t = int(input())
for i in range(t):
    a, b = map(int, input().split())
    if b > a:
        a, b = b, a
    if a > b:
        if a >= b * 2:
            print(a ** 2)
        else:
            print((a + 1) ** 2)
    else:
        print((a * 2) ** 2)