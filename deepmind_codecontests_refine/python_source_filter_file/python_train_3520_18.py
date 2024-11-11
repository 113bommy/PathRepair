N=int(input())
A=list(map(int,input().strip().split(" ")))
dp=[[10**10]*len(A)  for i in range(0,len(A)+1)]
##dp[length][start_position]
pre=[]
temp=0
for i in range(len(A)):
    temp+=A[i]
    pre+=[temp]
length=1
for i in range(len(A)):
    dp[length][i]=0

for L in range(2,len(A)+1):
    for start in range(0,len(A)-L+1):
        for j in range(start+1,start+L):
            if start>0:
                dp[L][start]=min(dp[j-start][start]+dp[L-j+start][j]+pre[start+L-1]-pre[start-1],dp[L][start])
            else:
                dp[L][start]=min(dp[j-start][start]+dp[L-j+start][j]+pre[start+L-1],dp[L][start])
print(dp[len(A)][0])