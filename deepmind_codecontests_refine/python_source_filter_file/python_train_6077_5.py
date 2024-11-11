import math
n = int(input())
l = list(map(int,input().split()))[:n]
dp = [0 for j in range(max(l)+1)]
for x in l:
    divi = set()
    for k in range(2,int(math.sqrt(x))+1):
        if not x%k:
            divi.add(x%k)
            divi.add(k)
    divi.add(x)
    if divi:
        dp[x]=max([dp[k] for k in divi])+1
        for d in divi:
            dp[d]=dp[x]
if len(l)==1:
    print(1)
else:
    print(max(dp))
            
