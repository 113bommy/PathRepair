X, Y = list(map(int,input().split()))

N = X

if X % Y == 0:
	print(-1)

else:
	while  N % Y == 0:
		N += X
	print(N)
