matr = [None] * 4

i = 0
while i < 4:
    matr[i] = input()
    i += 1

flag = False

y = 0
while y < 3:
    i = 0
    while i < 3:
        count = 0
        if matr[y][i] == '#':
            count += 1

        if matr[y][i + 1] == '#':
            count += 1

        if matr[y + 1][i] == '#':
            count += 1

        if matr[y + 1][i + 1] == '#':
            count += 1

        if count != 2:
            flag = True
            y = 3  # Stop processing
            i = 3

        i += 1

    y += 1

if flag:
    print("YES")
else:
    print("NO")
