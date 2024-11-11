n = int(input())
arr = list(map(int, input().split()))
dp = [[0] * 5 for i in range(n)]
dp[0] = [1, 1, 1, 1, 1]

for i in range(1, n):
    if arr[i] > arr[i - 1]:
        for j in range(1, 5):
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - 1])
    elif arr[i] < arr[i - 1]:
        for j in range(3, -1, -1):
            dp[i][j] = max(dp[i - 1][j + 1], dp[i][j + 1])
    else:
        for j in range(5):
            dp[i][j] += (sum(dp[i - 1]) > 0) * (dp[i - 1][j] == 0 or sum(dp[i - 1]) > 1)
if dp[-1] == [0, 0, 0, 0, 0]:
    print(-1)
else:
    ans = [dp[-1].index(1) + 1]
    for i in range(n - 2, -1, -1):
        for j in range(5):
            if dp[i][j] > 0 and ((j + 1 > ans[-1] and arr[i] > arr[i + 1])
                                 or (j + 1 < ans[-1] and arr[i] < arr[i + 1])
                                 or (j + 1 != ans[-1] and arr[i] == arr[i + 1])):
                ans.append(j + 1)
                break
    print(*reversed(ans))
