def solve(x,y,ind):
	if x==101 and y==101 and ind!=0:
		return 0
	if ind==n:
		return -ind
	if dp[x][y][ind]!=-1:
		return dp[x][y][ind]
	ans=0
	ans=solve(x,y,ind+1)
	if c[ind]=='L':
		ans=max(ans,1+solve(x-1,y,ind+1))
	elif c[ind]=='R':
		ans=max(ans,1+solve(x+1,y,ind+1)) 
	elif c[ind]=='U':
		ans=max(ans,1+solve(x,y-1,ind+1))
	else:
		ans=max(ans,1+solve(x,y+1,ind+1))
	dp[x][y][ind]=ans
	return ans
n=int(input())
c=input()
dp=[[[-1]*(n+1) for i in range(202)] for j in range(202)]
print(solve(101,101,0))
