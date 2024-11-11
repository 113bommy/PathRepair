S=input()
dp=[[0 for _ in range(13)] for _ in range(len(S))]
MOD=10**9+7
if S[0]=='?':
  for i in range(10):
    dp[0][i]=1
else:
  dp[0][int(S[0])]+=1
for i in range(1, len(S)):
  cur_nums=[i for i in range(10)] if S[i]=='?' else [int(S[i])]
  for cur in cur_nums:
    for rem in range(13):
      dp[i][(10*rem+cur)%13]=(dp[i][(10*rem+cur)%13]+dp[i-1][rem])%MOD
print(dp[-1][5])