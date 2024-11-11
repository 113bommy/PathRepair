import sys
from sys import stdin, stdout  
def R():
    return map(int, stdin.readline().strip().split())

n, m, c, d = R()

arr1 = []
for i in range(n//c):
    arr1.append((c, d))
for i in range(m):
    a, b, c, d = R()
    for j in range(min(a//b, n//c)):
        arr1.append((c, d))

dp = [[0 for i in range(n+1)] for i in range(len(arr1))]
if len(dp) == 0:
    print(0)
    exit()
for i in range(len(arr1)):
    c, d = arr1[i-1]
    for w in range(n+1):
        dp[i][w] = dp[i-1][w]
        if w >= c:
            if dp[i-1][w-c] + d > dp[i][w]:
                dp[i][w] = dp[i-1][w-c] + d
print(dp, arr1)
stdout.write(str(dp[-1][-1]))
# print(arr1)
# for i in dp:
#     print(i)