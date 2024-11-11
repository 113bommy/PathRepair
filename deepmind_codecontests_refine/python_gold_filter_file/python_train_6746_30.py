import bisect
N = int(input())
A = [-int(input()) for i in range(N)]


dp = []
for a in A:
    i = bisect.bisect_right(dp, a)
    if i >= len(dp):
        dp.append(a)
    else:
        dp[i] = a

print(len(dp))