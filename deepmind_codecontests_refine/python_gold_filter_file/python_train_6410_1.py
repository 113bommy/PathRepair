n, m, k, x, y = map(int, input().split())
matrix = [[0] * m for i in range(n)]
in_cycle = (n + n - 2) * m
if n == 1:
    in_cycle = m
    for i in range(m):
        matrix[0][i] += k // in_cycle
    k %= in_cycle
    for i in range(m):
        if k > 0:
            matrix[0][i] += 1
            k -= 1
    mx = -1
    mn = 10 ** 19
    for i in matrix:
        mx = max(mx, max(i))
        mn = min(mn, min(i))
    print(mx, mn, matrix[x - 1][y - 1])            
else:
    for i in range(m):
        matrix[0][i] += k // in_cycle
        matrix[-1][i] += k // in_cycle
    for i in range(1, n - 1):
        for j in range(m):
            matrix[i][j] += (k // in_cycle) * 2
    k %= in_cycle
    for i in range(n):
        for j in range(m):
            if k > 0:
                matrix[i][j] += 1
                k -= 1
    for i in range(n - 2, -1, -1):
        for j in range(m):
            if k > 0:
                matrix[i][j] += 1
                k -= 1
    mx = -1
    mn = 10 ** 19
    for i in matrix:
        mx = max(mx, max(i))
        mn = min(mn, min(i))
    print(mx, mn, matrix[x - 1][y - 1])