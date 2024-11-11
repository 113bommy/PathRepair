n, m = map(int,input().split())
a = sorted(map(int,input().split()))[::-1]
c = [0,2,5,5,4,5,6,3,7,6]
dp = [-float('inf')]*(n+1)
dp[0] = 0
for i in range(2, n+1):
    for j in a:
        if i >= j:
            dp[i] = max(dp[i], dp[i-c[j]]+1)
r = []
while n:
    i = max((i for i in a if n>=c[i]), key=lambda x: dp[n-c[x]])
    r.append(i)
    n -= c[i]
print(''.join(map(str, r)))