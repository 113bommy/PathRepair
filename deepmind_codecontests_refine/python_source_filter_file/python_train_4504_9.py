def solve():
    n, m = map(int, input().strip().split())
    grid = []
    possible = True
    for i in range(n):
        row = list(map(int, input().strip().split()))
        grid.append(row)
    possible = possible and not(
        grid[0][0] > 2 or grid[0][m-1] > 2 or grid[n-1][0] > 2 or grid[n-1][m-1] > 2)
    for i in range(1, m-1):
        possible = possible and not(grid[0][i] > 3)
        possible = possible and not(grid[n-1][i] > 3)
    for i in range(1, n-1):
        possible = possible and not(grid[i][0] > 3)
        possible = possible and not(grid[i][n-1] > 3)
    for y in range(1, n-1):
        for x in range(1, m-1):
            possible = possible and not(grid[y][x] > 4)
    if possible:
        print("YES")
        print("2", end=" ")
        for x in range(1, m-1):
            print("3", end=" ")
        print("2")
        for y in range(1, m-1):
            print("3", end=" ")
            for x in range(1, m-1):
                print("4", end=" ")
            print("3")
        print("2", end=" ")
        for x in range(1, m-1):
            print("3", end=" ")
        print("2")
    else:
        print("NO")


t = int(input().strip())

for _ in range(t):
    solve()
