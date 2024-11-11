N=int(input())
ABC=[]
for i in range(N):
	ABC+=[[int(i) for i in input().split()]]
DP=[[0,0,0] for i in range(N)]
for i in range(1,N):
	for j in range(3):
		DP[i][j]=ABC[i][j]+max(DP[i-1][(j+1)%3],DP[i-1][(j+2)%3])
print(max(DP[-1]))

