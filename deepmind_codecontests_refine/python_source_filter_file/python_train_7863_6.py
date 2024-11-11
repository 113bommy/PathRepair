from sys import stdin
stdin.readline
def mp(): return list(map(int, stdin.readline().strip().split()))
def it():return int(stdin.readline().strip())

# n=it()
# l=mp()

# dp=[[0 for i in range(3)] for j in range(105)]


# for i in range(1,n+1):

# 	dp[i][0]=max(dp[i-1])

# 	if l[i-1] == 3:
# 		dp[i][1] = max(dp[i-1][0]+1,dp[i-1][2]+1)
# 		dp[i][2] = max(dp[i-1][0]+1,dp[i-1][1]+1)
# 	elif l[i-1] == 2:
# 		dp[i][2] = max(dp[i-1][0]+1,dp[i-1][1]+1)
# 	elif l[i-1] == 1:
# 		dp[i][1] = max(dp[i-1][0]+1,dp[i-1][2]+1)
# # print(dp)
# print(n-max(dp[n]))


n=it()
l=mp()

prev=l[0]
ans=0
for i in range(1,n):
	if l[i]==0 or l[i]==prev:
		ans+=1
		prev=0
	elif l[i]==2:
		prev=2
	elif  l[i]==1:
		prev=1
	else:
		if prev>0:
			prev=3-prev
print(ans)
