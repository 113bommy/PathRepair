n=int(input())
h=list(map(int,input().split()))
DP=[0]*n
DP[0]=0
DP[1]=abs(h[0]-h[1])
for i in range(n-2):
    DP[i+2]=min(DP[i]+abs(h[i]-h[i+2]),DP[i+1]+abs(h[i+2]-h[i+1]))
print(DP)