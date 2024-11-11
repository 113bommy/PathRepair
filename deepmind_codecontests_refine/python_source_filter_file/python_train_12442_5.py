n,m = [int(i) for i in input().strip().split()]
grid = [[int(i) for i in input().strip().split()] for j in range(n)]
ans = int(1e10)
for i in range(n):
    ans = max(ans,min(grid[i]))
print(ans)