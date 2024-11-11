n = int(input())
if n % 4 == 0:
    print("0")
    L = []
    L.append(str(int(n // 2)))
    for i in range(n // 4):
        L.append(str(i + 1))
        L.append(str(n - i))
    print(" ".join(L))
elif n % 4 == 1:
    print("1")
    L = []
    L.append(str(n // 2))
    for j in range((n - 1) // 4):
        L.append(str(j + 2))
        L.append(str(n - j))
    print(" ".join(L))
elif n % 4 == 2:
    print("1")
    L = []
    L.append(str(n // 2))
    for k in range(n // 4):
        L.append(str(k + 3))
        L.append(str(n - k))
    L.append(str(n - 1))
    print(" ".join(L))
elif n % 4 == 3:
    print("0")
    L = []
    L.append(str(n // 2))
    for l in range(n // 4):
        L.append(str(l + 4))
        L.append(str(n - l))
    L.append(str(3))
    print(" ".join(L))
