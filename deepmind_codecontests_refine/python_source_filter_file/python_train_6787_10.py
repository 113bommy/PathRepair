a,b=map(int,input().split())
t=max(a,b)
j=min(a,b)
a,b=t,j
dp=[2,4]
for i in range(2,a+1):
    dp.append(0)
if a<3:
    row=dp[a-1]
else:
    for i in range(2,a):

        dp[i]=dp[i-1]+dp[i-2]
    # print(dp)
    row=dp[a-1]

# dp=[row,row+2]
# for i in range(2,b+1):
#     dp.append(0)
# if b<3:
#     row=dp[b-1]
# else:
#     for i in range(2,b):
#         dp[i]=dp[i-1]+dp[i-2]    
#     row=dp[b-1]
if b-2<0:
    print(row%(10**9+7))
else:
    print((row+dp[b-2])%(10**9+7))

