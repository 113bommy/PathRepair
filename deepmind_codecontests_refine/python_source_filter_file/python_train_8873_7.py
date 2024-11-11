for i in range(int(input())):
    n = int(input())
    matrix = []
    is_ = True
    for j in range(n):
        matrix.append(list(input()))
    for row in range(len(matrix)):
        for col in range(len(matrix[0])):
            if row == n - 1 or col == n - 1:
                continue
            else:
                if matrix[row][col] == '1':
                    if matrix[row][col + 1] != '1' and matrix[row + 1][col] != '1':
                        print('NO')
                        is_ = False
                        break
    if is_:
        print('YES')