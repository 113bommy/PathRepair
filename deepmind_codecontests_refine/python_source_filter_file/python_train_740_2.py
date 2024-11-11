def gen_matrix(matrix, count, n):
    c = 0
    if n % 2 == 0:
        for i in range(n // 2):
            for j in range(n // 2):
                while count[c] == 0:
                    c += 1
                matrix[i][j] = matrix[n - 1 - i][j] = matrix[i][n - 1 - j] = matrix[n - 1 - i][n - 1 - j] = c + 1
                count[c] -= 4
    else:
        for i in range(n // 2):
            for j in range(n // 2):
                while count[c] < 4:
                    c += 1
                matrix[i][j] = matrix[n - 1 - i][j] = matrix[i][n - 1 - j] = matrix[n - 1 - i][n - 1 - j] = c + 1
                count[c] -= 4
        c = 0
        for i in range(n // 2):
            while count[c] < 2:
                c += 1
            matrix[i][n // 2] = matrix[n - 1 - i][n // 2] = c + 1
            count[c] -= 2
        for j in range(n // 2):
            while count[c] < 2:
                c += 1
            matrix[n // 2][j] = matrix[n // 2][n - 1 - j] = c + 1
            count[c] -= 2
        c = 0
        while count[c] < 1:
            c += 1
        matrix[n // 2][n // 2] = c + 1

n = int(input())

count = [0] * 1000

matrix = [[0] * n for _ in range(n)]

for a in map(int, input().split()):
    count[a - 1] += 1

even = n % 2
pair = (n - 1) * (n % 2)

for c in count:
    if c % 4:
        even -= c % 2
        pair -= 1 if c > 1 else 0

if even >= 0 and pair >= 0:
    print('YES')
    gen_matrix(matrix, count, n)
    for i in range(n):
        for j in range(n-1):
            print(matrix[i][j], end=' ')
        print(matrix[i][n-1])
else:
    print('NO')

