n, m = map(int, input().strip().split())
arr = []
for i in range(n): arr.append(list(input())) 

dp = [[float('inf') for i in range(3)] for i in range(n)]
for i in range(n):
    for j in range(m):
        if ord('a') <= ord(arr[i][j]) <= ord('z'):
            dp[i][0] = min(dp[i][0], j, m-j)
        elif arr[i][j] in '&#*':
            dp[i][1] = min(dp[i][1], j, m-j)
        else:
            dp[i][2] = min(dp[i][2], j, m-j)

ans = float('inf')
for i in range(n):
    for j in range(n):
        for k in range(n):
            if len(set([i, j, k])) == 3:
                # print(i, j, k, 'check')
                ans = min(dp[i][0] + dp[j][1] + dp[k][2], ans)

# for i in dp:
#     print(i)

print(ans)
    

