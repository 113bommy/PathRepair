def solution():
    m, n = [int(i) for i in input().split()]
    grid = []
    for i in range(m):
        grid.append(input())

    left = n - 1
    right = 0
    top = m - 1
    bottom = 0

    for i in range(m):
        for j in range(n):
            if grid[i][j] == '*':
                top = min(top, i)
                bottom = max(bottom, i)
                left = min(left, j)
                right = max(right, j)
    # print(left, right, top, bottom)
    for i in range(top, bottom + 1):
        print(' '.join(grid[i][left: right + 1]))





if __name__ == "__main__":
    solution()