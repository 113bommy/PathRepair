n,t=[int(j) for j in input().split()]
ab=[]
ans=[]
dp=[0]*t
for i in range(n):
    tmp=[int(j) for j in input().split()]
    ab.append(tmp)
ab.sort()
for a,b in ab:
    for i in range(t)[::-1]:
        if dp[i]!=0 or i==0:
            if i+a>=t:
                ans.append(dp[i]+b)
            else:
                dp[i+a]=max(dp[i+a],dp[i]+b)
if ans:
    print(max(ans))
else:
    print(max(dp))