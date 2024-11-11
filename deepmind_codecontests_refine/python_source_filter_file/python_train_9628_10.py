def main():
    n, k = map(int, input().split())
    grid = [['S' for _ in range(n)] for _ in range(n)]
    lands = 0
    for i in range(n):
        for j in range(n):
            if (i + j) % 2 == 1 and lands < k:
                grid[i][j] = 'L'
                lands += 1

    if lands != k:
        print('NO')
    else:
        print('YES')
        for row in grid:
            print(''.join(row))

main()
