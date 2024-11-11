from sys import stdin, stdout
MX = 10**15 + 5
n = int(stdin.readline())
c = []
c = list(map(int , input().split(' ')))
s = []
for i in range(n):
    s.append(input())
dp = []
for i in range(n):
    dp.append([0, c[i]])
flag = True

for i in range(1,n):
    mn1 = MX
    if (s[i-1] <= s[i] and dp[i-1][0] >= 0):
        mn1 = min(mn1, dp[i-1][0])
    if (s[i-1][::-1] <= s[i] and dp[i-1][1] >= 0):
        mn1 = min(mn1, dp[i-1][1])
    mn2 = MX
    if (s[i-1] <= s[i][::-1] and dp[i-1][0] >= 0):
        mn2 = min(mn2, dp[i-1][0])
    if (s[i-1][::-1] <= s[i][::-1] and dp[i-1][1] >= 0):
        mn2 = min(mn2, dp[i-1][1])
    if mn1 >= MX and mn2 >= MX:
        flag = False
        break
    if mn2 < MX:
        dp[i][1] += mn2
    else:
        dp[i][1] = -1
    if mn1 < MX:
        dp[i][0] += mn1
    else:
        dp[i][0] = -1

ans = min(dp[-1][0], dp[-1][1])
if ans < 0:
    ans = max(dp[-1][0], dp[-1][1])
if flag:
    stdout.write(str(ans)) 
else:
    stdout.write(str(-1))