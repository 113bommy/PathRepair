N,K=list(map(int,input().strip().split(' ')))
A=[]
for _ in range(N):
    A+=[list(map(int,input().strip().split(' ')))]
dic={}
MOD=10**9+7
power=1
while 2**power<=K:
    power+=1

dp=[[[0 for j in range(N)] for i in range(N)] for p in range(power+1) ]
for p in range(0,power+1):
    
    if p==0:
        for i in range(N):
            for j in range(N):
                if A[i][j]==1:
                    dp[p][i][j]=1
    else:
        for i in range(N):
            for j in range(N):
                for k in range(N):
                    dp[p][i][j]+=(dp[p-1][i][k]*dp[p-1][k][j])%MOD
                    dp[p][i][j]%=MOD

    
rep=bin(K)[2:][::-1]
final_ans=[[0 for i in range(N)] for j in range(N)]
need=[]
for i in range(len(rep)):
    if rep[i]=="1":
        need+=[i]

final=[[dp[need[0]][i][j] for j in range(N)] for i in range(N)]
for i in range(len(need[1:])):
    ##start*dp[need[i]]
    temp_ans=[[0 for i in range(N)] for j in range(N)]
    for x in range(N):
        for y in range(N):
            temp=0
            for z in range(N):
                temp+=final[x][z]*dp[need[i]][z][y]
                temp%=MOD
            temp_ans[x][y]=temp
    final=[[temp_ans[i][j] for j in range(N)] for i in range(N)]
            
ans=0
for i in range(N):
    for j in range(N):
        ans+=final[i][j]
        ans%=MOD
print(ans)
