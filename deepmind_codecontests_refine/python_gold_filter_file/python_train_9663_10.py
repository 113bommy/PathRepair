#i文字目を見て，それより前のAの個数，ABの個数，ABCの個数を持っておく

S=input()
N=len(S)
dp=[0,0,0]

mod=10**9+7


count=0#?の数
for i in range(N):
    if S[i]=="A":
        dp[0]=(dp[0]+pow(3,count,mod)) %mod
    elif S[i]=="B":
        dp[1]=(dp[1]+dp[0])%mod
    elif S[i]=="C":
        dp[2]=(dp[2]+dp[1])%mod
    else:
        dp[2]=(dp[2]*3+dp[1])%mod
        dp[1]=(dp[1]*3+dp[0])%mod
        dp[0]=(dp[0]*3+pow(3,count,mod))%mod
        count+=1
        
print(dp[2]%mod)   





