N = int(input())
arr = input()
l = list(map(int,arr.split(' ')))
dp = [1]*N
for i in range(1,N):
    if(l[i] > l[i-1]):
        dp[i] = dp[i-1]+1

max = 0
for i in range(1,N):
    if dp[max] < dp[i]:
        max = i

print(dp[max])