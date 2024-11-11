for _ in range(int(input())):
    n = int(input())
    a = [input() for _ in range(n)]

    for color in range(2):

        result = []
        if int(a[0][1]) != color:
            result.append((0, 1))
        if int(a[1][0]) != color:
            result.append((1, 0))
        if int(a[n - 1][n - 2]) == color:
            result.append((n - 1, n - 2))
        if int(a[n - 2][n - 1]) == color:
            result.append((n - 2, n - 1))

        if len(result) < 3:
            print(len(result))
            for x, y in result:
                print(x, y)
            break
