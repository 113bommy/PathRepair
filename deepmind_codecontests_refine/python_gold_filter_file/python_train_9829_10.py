def table(lst, n, m):
    for i in range(n):
        for j in range(m):
            if lst[i][j] == '1':
                if i == 0 or i + 1 == n or j == 0 or j + 1 == m:
                    return 2
    return 4


N, M = [int(x) for x in input().split()]
arr = [input().split() for i in range(N)]
print(table(arr, N, M))
