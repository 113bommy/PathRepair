t = int(input())

for _ in range(t):
    a, b = list(map(int, input().split(" ")))

    a_mod4 = (a - 1) % 4

    # print("mod4 =", a_mod4)
    if a_mod4 == 0:
        xor = a - 1
    elif a_mod4 == 1:
        xor = 1
    elif a_mod4 == 2:
        xor = a
    else:
        xor = 0

    # print("xor =", xor)
    # print("xor ^ b =", xor ^ b)
    if xor == b:
        print(a)
    else:
        if xor ^ b <= a:
            print(a + 2)
        else:
            print(a + 1)
