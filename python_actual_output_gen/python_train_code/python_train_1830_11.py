n,k=map(int,input().split())
r,s,p=map(int,input().split())
t=input()

dp=[0]*n
a = {"r":p, "s":r, "p":s}

for i in range(n):
    if i>=k and t[i]==t[i-k]: # どうせ得点できないので、次に影響しないように'x'
        dp[i]=0
        t[i]='x'
    else:
        dp[i]=d[t[i]]   
print(sum(dp))