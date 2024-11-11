# map(int, input().split(" "))

n = int(input())
dp = [[1,1,1] for i in range(n)]
l = list(map(int, input().split(" ")))

for i in range(1,n):
    if l[i] == l[i-1]:
        dp[i][0]+=dp[i-1][0]
        dp[i][1]+=dp[i-1][1]
        dp[i][2]+=dp[i-1][2]
    if l[i] == l[i-1]-1:
        dp[i][2] += max(dp[i-1][1], dp[i-1][0])
    if l[i] == l[i-1]+1:
        dp[i][0] += max(dp[i-1][1], dp[i-1][2])
ans = 0
for i in dp:
    ans = max(ans, max(i))
# print(dp)
print(ans)