n = int(input())
if n < 3:
    print('0')
else:
    m = tuple((input().lower() for _ in range(n)))
    res = 0
    for i in range(1, n - 1):
        for j in range(1, n - 1):
            if m[i][j] == m[i - 1][j - 1] == m[i - 1][j + 1] == m[i + 1][j - 1] == m[i + 1][j + 1] == 'x':
                res += 1
    print(res)
