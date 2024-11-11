n = int(input())
A = list(map(int,input().split()))
B = A[1:n]
С = [A[0],]
if A[0] == 0 or sum(A) < n - 1:
	print(-1)
else:
	for i in range(n):
		A[i]= (A[i],i)
	A = [A[0]] + sorted(A[1:],reverse=True)
	S = [0] * n
	S[0] = 1
	Ans = []
	x = 0
	y = 1
	while(x < n and A[x][0] != 0):
		for i in range(A[x][0]):
			if (y < n):
				S[y] = 1
				Ans.append((A[x][1], A[y][1]))
				y += 1
			x +=1
	print(len(Ans))
	for i in Ans:
		print(i[0] + 1, i[1] + 1)