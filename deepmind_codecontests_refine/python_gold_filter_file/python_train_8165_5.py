n=int(input())
a=list(map(int,input().split()))
dp=[0]*(max(a)+1)
cnt = [0]*(max(a)+1)

for i in a:
    cnt[i]+=1

dp[0] = 0
dp[1] = cnt[1]

for j in range(2,max(a)+1):
    dp[j]=max(dp[j-1],dp[j-2]+cnt[j]*j)
print(max(dp))