N = int(input())
X = list(map(int, input().split()))
from collections import defaultdict
dp = defaultdict(lambda :-1)
for i in range(N):
    dp[i+1001] = X[i]
for i in range(2, N+1):
    for j in range(N-i+1):
        for k in range(1, i):
            u, v = dp[j+1001*k], dp[j+k+1001*(i-k)]
            if u == -1 or v == -1 or u != v:
                continue
            dp[j+1001*i] = u+1;break
 
 
#print(dp)
dp2 = [0]*(N+1)
for i in range(N):
    dp2[i+1] = dp[i]+1
    if dp[1001*(i+1)] != -1:
        dp2[i+1] = 1
        continue
    for j in range(i+1):
        if dp[j+(i+1-j)*1001] == -1:
            continue
        dp2[i+1] = min(dp2[i+1], dp2[j]+1)
print(dp2[-1])