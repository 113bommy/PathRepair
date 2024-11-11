dp=[0]*200005
mod = 1000000007
dp[2]=2
dp[1]=1
for i in range(3,100005):
    dp[i]=(dp[i-1]+dp[i-2])%mod
s = list(input())
if ('m' in s) or ('w' in s):
    print(0)
else:
    ans=1
    c=1
    for i in range(len(s)):
        if s[i]==s[i-1] and (s[i]=='n' or s[i]=='u'):
            c+=1
        else:
            if c>=2:
                ans=(ans*dp[c])%mod
            c=1
    if c>=2:
        ans=(ans*dp[c])%mod        
    print(ans)        
