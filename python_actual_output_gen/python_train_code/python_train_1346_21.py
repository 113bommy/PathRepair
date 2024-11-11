m, n = map(int, input().split())
s = 0

for i in range (m):
    for j in range (n):
        if (i + 1) % 2 != 0:
            if j < m - 1:
                print("#", end = "")
            else:
                print("#")
        elif (i + 1) % 2 == 0 and s % 2 != 0:
            if j < m - 1:
                print(".", end = "")
            else:
                print("#")
        elif (i + 1) % 2 == 0 and s % 2 != 1:
            if j == 0:
                print("#", end = "")
            elif j < m - 1:
                print(".", end = "")
            else:
                print(".")
    if i % 2 == 0:
        s += 1