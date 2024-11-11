
def solve():
    n = int(input())
    if n == 1:
        print("1")
        return
    if n == 2:
        print("-1")
        return
    grid = []
    for i in range(1, n+1):
        ve = []
        for j in range(1, n+1):
            ve.append(0)
        grid.append(ve)

    odd = 1
    even = 2
    for i in range(0, n):
        for j in range(0, n):
            if(odd < n*n):
                grid[i][j] = odd
                odd += 2
            else:
                grid[i][j] = even
                even += 2
    for i in range(0, n):
        for j in range(0, n):
            print(grid[i][j], end=" ")
        print("\n")




#main
testCase = int(input())

for i in range(0, testCase):
    solve()