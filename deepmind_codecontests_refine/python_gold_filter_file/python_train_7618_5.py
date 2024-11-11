if __name__ == '__main__':
    n, m = list(map(int, input().split()))
    matrix = []
    for i in range(n):
        matrix.append(list(map(int, input().split())))
    res = 0
    for i in range(n - 2, 0, -1):
        for j in range(m - 2, 0, -1):
            if matrix[i][j] == 0:
                new = min(matrix[i + 1][j], matrix[i][j + 1]) - 1
                if (matrix[i - 1][j] == 0 or new > matrix[i - 1][j]) and (matrix[i][j - 1] == 0 or new > matrix[i][j - 1]):
                    matrix[i][j] = new
                else:
                    res = -1
                    break
        if res == -1:
            break
    if res != -1:
        for i in range(n):
            for j in range(1, m):
                if matrix[i][j] <= matrix[i][j - 1]:
                    res = -1
        if res == -1:
            print(-1)
        else:
            for i in range(m):
                for j in range(1, n):
                    if matrix[j][i] <= matrix[j-1][i]:
                        res = -1
            if res == -1:
                print(-1)
            else:
                for i in range(n):
                    res += sum(matrix[i])
                print(res)
    else:
        print(-1)
