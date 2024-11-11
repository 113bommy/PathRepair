a, b = map(int, input().split())
i = 1
while a >= i and b >= i:
    a -= i
    i += 1
    if b < i:
        print("Valera")
        exit()
    b -= i
    i += 1
    if a < i:
        print("Vladik")
        exit()
