from collections import Counter
N=int(input())
p=[]
dp=[[0]*100 for _ in range(100)]
dp[0][1]=1

for i in range(2,N+1):
    ti=i
    for j in range(2,i+1):
        while ti%j==0:
            p.append(j)
            ti//=j

cnt=Counter(p)
ans=0
for i,v in enumerate(cnt.values()):
    for j in range(100):
        for k in range(1,v+2):
            dp[i+1][min(76,j*k)]+=dp[i][j]
    ans=dp[i+1][75]

print(ans)