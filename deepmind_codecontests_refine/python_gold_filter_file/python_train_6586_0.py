import sys
input = sys.stdin.buffer.readline

n = int(input())
a = list(map(int,input().split()))
dp = [n]*(n*(n+1))

dg = n+1

mi = [0]*(n+1)

for j in range(n+1):
    if j > a[0]:
        break
    if j == a[0]:
        dp[j] = j
    else:
        dp[j] = j+1

tmp = 2*n
for j in range(n+1):
    tmp = min(tmp , dp[j] + n-j)
    mi[j] = tmp



for i in range(1,n):
    for j in range(n,-1,-1):
        if j > a[i]:
            continue
        if j != n:
            tmp = dp[i*dg + j+1]
        else:
            tmp = n

        
        if a[i] > j:
            tmp = min(tmp , dp[(i-1)*dg + j] + 1)
        else:
            tmp = min(tmp , dp[(i-1)*dg +j])
        
        if j != 0:
            if a[i] > j:
                tmp = min(tmp , mi[j-1] + j-n + 1)
            else:
                tmp = min(tmp , mi[j-1] + j-n)


        dp[i*dg + j] = tmp
    tmp = 2*n
    for j in range(n+1):
        tmp = min(tmp , dp[i*dg + j] + n-j)
        mi[j] = tmp


print(dp[(n-1)*dg])