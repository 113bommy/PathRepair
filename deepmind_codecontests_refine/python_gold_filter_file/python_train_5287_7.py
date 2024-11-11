n = int(input())
from collections import defaultdict
a = list(map(int,input().split()))
ans = 0
dp = defaultdict(int)
for e,i in enumerate(a,1):
    if  e - i>= 0 :ans += dp[e-i]
    dp[i+e]+=1
print(ans)
