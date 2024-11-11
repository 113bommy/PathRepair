
n = int(input())
l1 = l2 = l3 = 0
l = [int(i) for i in input().split()]
for i in l:
    if i == 1:
        l1 += 1
    elif i == 2:
        l2 += 1
    else:
        l3 += 1
a = l2+l3
dp = [[[0.0]*(l3+1) for i in range(a+1)] for j in range(n+1)]

for i in range(1,n+1):
    for j in range(min(i,a)+1):
        for k in range(min(j,l3)+1):
            s = i-j
            t = j-k
            count = n/(s+t+k)
            if s > 0:
                count += dp[s-1][t][k]*(s/(s+t+k))     
            if t > 0 :
                count += dp[s+1][t-1][k]*(t/(s+t+k))
            if k > 0 :
                count += dp[s][t+1][k-1]*(k/(s+t+k))

            dp[s][t][k] = count

print(dp[l1][l2][l3])


