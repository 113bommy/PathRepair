n = int(input())
from collections import defaultdict
a = list(map(int,input().split()))
ans = 0
dp = defaultdict(int)
for e,i in enumerate(a,1):
    if i - e >= 0 :ans += dp[i-e]
    dp[i+e]+=1
print(ans)
