import sys

try:
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')
except:
    pass

n, k = map(int, input().split())
a = list(map(int, input().split()))

dp = [0]*(n-k+1)
sum_ = sum(a[:k])
dp[0] = sum_
for i in range(k, n):
    sum_ += (a[i]-a[i-k])
    dp[i-k+1] = sum_

suff_min = [0]*(n-k+1)
suff_min[-1] = n-k
for i in range(len(suff_min)-2, -1, -1):
    suff_min[i] = suff_min[i+1]

    if dp[i] >= dp[suff_min[i+1]]:
        suff_min[i] = i

# print(dp, suff_min)
ans = 0
a, b = 0, 0
for i in range(len(dp)-k-1):
    if dp[i] + dp[suff_min[i+k]] > ans:
        # print(i)
        a, b = i, suff_min[i+k]
        ans = dp[i] + dp[suff_min[i+k]] 
    
print(a+1, b+1)


    
