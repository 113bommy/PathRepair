T = int(input())
for i in range(0, T):
	S = str(input())
	m = int(input())
	B = list(map(int , input().split()))
	vis = []
	ans_int = []
	S_int = []
	for j in range(0, m):
		vis.append(0)
		ans_int.append(0)
	for j in range(0, len(S)):
		S_int.append(ord(S[j]))
	S_int.sort()
	S_int.reverse()
	tar = 0
	indi = 0
	while tar<m:
		mark = []
		for j in range(0, m):
			if B[j] == 0 and vis[j] == 0:
				mark.append(j)
				vis[j] = 1
		leng = len(mark)
		# print(indi)
		# print(B)
		for j in range(0, m):
			for k in range(0, leng):
				if vis[j] == 0:
					B[j] -= abs(j-mark[k])
		y = S_int[indi]
		while True:
			x = S_int[indi]
			flag = 1
			for k in range(1, leng):
				if S_int[indi+k] != x:
					flag = 0
					break
			if flag == 0:
				indi += 1
			else:
				break
		for j in range(0, leng):
			ans_int[mark[j]] = S_int[indi]
			indi += 1
		while indi < len(S) and S_int[indi] == y:
			indi += 1
		tar += leng
	ans = []
	for k in range(0, m):
		ans.append(chr(ans_int[k]))
	X = ""
	ans = X.join(ans)
	print(ans)


		








