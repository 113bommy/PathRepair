for _ in range(int(input())):
    n, m = map(int, input().split())
    matrix = []
    for _ in range(n):
        *row, = map(int, input().split())
        matrix.append(row)
    sign = 0
    s = 0
    mn = abs(matrix[0][0])
    for row in matrix:
        for v in row:
            if v < 0:
                sign = 1 - sign
            s += abs(v)
            mn = min(mn, abs(v))
    if v == 0:
        print(s)
    else:
        print(s - 2 * mn)




