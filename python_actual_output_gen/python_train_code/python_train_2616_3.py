n, m = map(int, input().split())
matrix, result, ck = [], 0, False
for _ in range(n):
    matrix.append(list(map(int, input().split())))
for i in range(n-1, -1, -1):
    for j in range(m-1, -1, -1):
        if matrix[i][j] == 0:
            matrix[i][j] = min(matrix[i][j+1], matrix[i+1][j]) - 1
for i in range(n-1):
    for j in range(m-1):
        if matrix[i][j] >= matrix[i][j+1] or matrix[i][j] >= matrix[i+1][j]:
            ck = True
            break
        if ck:
            break
for row in matrix:
    result += sum(row)
if ck or matrix[-1][-1] < matrix[-2][-1] or matrix[-1][-1] < matrix[-1][-2]:
    print(-1)
else:
    print(result)