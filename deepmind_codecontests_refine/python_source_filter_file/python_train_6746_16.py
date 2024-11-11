
import bisect

n = int(input())
num_list = []
for i in range(n):
    num_list.append(int(input()) * -1) 

dp = [1] * n 

for i in num_list:
    indx = bisect.bisect_left(dp, i)
    dp[indx] = min(dp[indx], i)

ans = sum(x < 1 for x in dp)

print(ans)