if __name__ == "__main__":
    numbers = list(map(int, input().split()))
    n = numbers[0]
    m = numbers[1]

    field = []
    field.append(' ' * (m + 2))

    for i in range(n):
        field.append(' ' + input() + ' ')

    field.append(' ' * (m + 2))

    allSheepAlive = True

    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if field[i][j] == 'W':
                if field[i + 1][j] == 'S' or field[i - 1][j] == 'S' or field[i][j + 1] == 'S' or field[i][j - 1] == 'S':
                    allSheepAlive = False

    if allSheepAlive is False:
        print("No")
        exit()

    print("Yes")
    for i in range(1, n + 1):
        print(field[i].replace(".", "D")[1:m])
