from collections import defaultdict
n=int(input())
l=list(map(int,input().split()))
d={}
d=defaultdict(int)
maxi=-99
for i in l:
    d[i]+=1
    maxi=max(i,maxi)
dp=[0]*(100001)
dp[1]=d[1]
for i in range(2,100000+1):
    dp[i]=max(dp[i-1],dp[i-2]+(d[i])*i)
print(max(dp))