n, k = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()
cnt = [0 for _ in range(n)]
for i in range(n):
    while i+cnt[i] < n and arr[i+cnt[i]] - arr[i] <= 5:
        cnt[i] += 1  # cnt[i] stores the maximum number of students belonging to a group(with <= 5 constraint)
        # starting from student i

dp = [[0 for _ in range(k+1)] for _ in range(n+1)]  # dp[i][j] is the maximum no. of students in at most j teams considering first i students
for i in range(n):
    for j in range(k):
        dp[i+1][j] = max(dp[i+1][j], dp[i][j])  # Do not take current student i
        if j+1 < k:
            dp[i+cnt[i]][j+1] = max(dp[i+cnt[i]][j+1], dp[i][j] + cnt[i])

print(dp[n-1][k-1])
