n = int(input())
a = list(map(int, input().split()))

dp = [[0] * n for _ in range(n) ]
sum_a = [[0] * n for _ in range(n) ]

for i in range(n):
    sum_a[i][i] = a[i]
    for j in range(i+1,n):
         sum_a[i][j] = sum_a[i][j-1] + a[j]

for i in range(1,n):
    for head in range(n-i):
        tail = head + i
        temp = 10**11
        for j in range(i):
            temp = min(temp, (dp[head][head+j] + dp[head+j+1][tail] + sum_a[head][tail]) )
        dp[head][tail] = temp

print(dp[0][n-1])