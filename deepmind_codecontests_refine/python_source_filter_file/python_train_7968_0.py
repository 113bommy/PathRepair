a = int(input())

if a < 3:
    print(-1)

elif a % 2 != 0:
    b = (a ** 2 - 1) / 2
    c = b + 1
    print(int(b), int(c))

else:
    b = (a / 2) ** 2 - 1
    c = b + 2
    print(int(b), int(c))

