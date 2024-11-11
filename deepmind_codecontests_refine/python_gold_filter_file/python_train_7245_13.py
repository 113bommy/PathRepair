A = [list(input()) for i in range(10)]

for i in range(10):
	A[i] += ["O"] * 5
for i in range(5):
	A.insert(0,["O"] * 15)
	A.append(["O"] * 15)
D = [(1,0),(0,1),(1,1),(-1,1)]
flag = False
for i in range(5,15):
	for j in range(10):
		if (A[i][j] == "X" or
			A[i][j + 1] == "X" or
			A[i + 1][j] == "X" or
			A[i + 1][j + 1] == "X" or
			A[i - 1][j + 1] == "X"):
			cnt = [0,0,0,0]
			for k in range(5):
				for n,d in enumerate(D):
					dx = k * d[0]
					dy = k * d[1]
					if A[i + dx][j + dy] == "X":
						cnt[n] += 1
					if A[i + dx][j + dy] == "O":
						cnt[n] = -10
			for c in cnt:
				if c == 4:
					flag = True
					break
		if flag == True:
			break
	if flag == True:
		break
if flag == True:
	print("YES")
else:
	print("NO")



