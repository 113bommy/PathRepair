def solve(m, mat):
    ans = 1e18
    topsum = sum(mat[0])
    botsum = 0
    for i in range(m):
        if i > 0:
            botsum += mat[1][i - 1]
        topsum -= mat[0][i]
        ans = min(ans, max(topsum, botsum))
    return ans

# print(solve(1, [[4], [7]]))
for t in range(int(input())):
    m = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    print(solve(m, [a, b]))
