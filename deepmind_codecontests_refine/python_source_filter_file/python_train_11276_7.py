import math

n,m,kk=[int(x) for x in input().split()]
right,down=[],[]
for i in range(n) :
	a=[int(x) for x in input().split()]
	right.append(a)

for i in range(n-1) :
	a=[int(x) for x in input().split()]
	down.append(a)

dp,dpCopy=[],[]
for i in range(n) :
	li=[]
	for j in range(m) :
		li.append(math.inf)
	dp.append(li)

for i in range(n) :
	li=[]
	for j in range(m) :
		li.append(math.inf)
	dpCopy.append(li)

for i in range(1,(kk//2)+1) :
	#print(i)
	for j in range(n) :
		for k in range(m) :
			if i==1 :
				if j==0 :
					if k==0 :
						dp[j][k]=min(dp[j][k],down[j][k],right[j][k])
					elif k==m-1 :
						dp[j][k]=min(dp[j][k],right[j][k-1],down[j][k-1])
					else :
						dp[j][k]=min(dp[j][k],right[j][k-1],right[j][k],down[j][k])
				elif j==n-1 :
					if k==0 :
						dp[j][k]=min(dp[j][k],down[j-1][k],right[j][k])
					elif k==m-1 :
						dp[j][k]=min(dp[j][k],right[j][k-1],down[j-1][k])
					else :
						dp[j][k]=min(dp[j][k],right[j][k-1],right[j][k],down[j-1][k])
				elif k==0 :
					dp[j][k]=min(dp[j][k],right[j][k],down[j-1][k],down[j][k])
				elif k==m-1 :
					dp[j][k]=min(dp[j][k],right[j][k-1],down[j-1][k],down[j][k])
				else :
					dp[j][k]=min(dp[j][k],right[j][k-1],right[j][k],down[j-1][k],dp[j][k])
				#print(dpCopy)
				continue

			if j==0 :
				if k==0 :
					dp[j][k]=min(dpCopy[j][k+1]+right[j][k],dpCopy[j+1][k]+down[j][k])
				elif k==m-1 :
					dp[j][k]=min(dpCopy[j][k-1]+right[j][k-1],dpCopy[j+1][k]+down[j][k])
				else :
					dp[j][k]=min(dpCopy[j][k-1]+right[j][k-1],dpCopy[j][k+1]+right[j][k],dpCopy[j+1][k]+down[j][k])
			elif j==n-1 :
				if k==0 :
					dp[j][k]=min(dpCopy[j-1][k]+down[j-1][k],dpCopy[j][k+1]+right[j][k])
				elif k==m-1 :
					dp[j][k]=min(dpCopy[j-1][k]+down[j-1][k],dpCopy[j][k-1]+right[j][k-1])
				else :
					dp[j][k]=min(dpCopy[j-1][k]+down[j-1][k],dpCopy[j][k-1]+right[j][k-1],dpCopy[j][k+1]+right[j][k])
			elif k==0 :
				dp[j][k]=min(dpCopy[j-1][k]+down[j-1][k],dpCopy[j+1][k]+down[j][k],dpCopy[j][k+1]+right[j][k])
			elif k==m-1 :
				dp[j][k]=min(dpCopy[j-1][k]+down[j-1][k],dpCopy[j+1][k]+down[j][k],dpCopy[j][k-1]+right[j][k-1])
			else :
				dp[j][k]=min(dpCopy[j-1][k]+down[j-1][k],dpCopy[j+1][k]+down[j][k],dpCopy[j][k-1]+right[j][k-1],dpCopy[j][k+1]+right[j][k])
			#print(dp)

	for ii in range(n) :
		for jj in range(m) :
			dpCopy[ii][jj]=dp[ii][jj]

if kk%2==1 :
	for i in range(n) :
		for j in range(m) :
			print(-1,end=' ')
		print()
	exit(0)

for i in range(n) :
	for j in range(m) :
		print(2*dp[i][j],end=' ')
	print()