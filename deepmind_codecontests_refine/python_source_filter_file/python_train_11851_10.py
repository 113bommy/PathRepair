N = int(input())

if N == 3:
	print(2, 5, 63)
elif N == 4:
	print(2, 5, 20, 63)
else:
	n = N // 8
	ans = []
	for i in range(n):
		ans.append(12 * i + 2)
		ans.append(12 * i + 3)
		ans.append(12 * i + 4)
		ans.append(12 * i + 6)
		ans.append(12 * i + 8)
		ans.append(12 * i + 9)
		ans.append(12 * i + 10)
		ans.append(12 * i + 12)
	j =  N % 8
	if j == 1:
		ans.append(12 * n + 3)
	elif j == 2:
		ans.append(12 * n + 3)
		ans.append(12 * n + 9)
	elif j == 3:
		ans.append(12 * n + 3)
		ans.append(12 * n + 9)
		ans.append(12 * n + 12)
	elif j == 4:
		ans.append(12 * n + 3)
		ans.append(12 * n + 9)
		ans.append(12 * n + 6)
		ans.append(12 * n + 12)
	elif j == 5:
		ans.append(12 * n + 2)
		ans.append(12 * n + 3)
		ans.append(12 * n + 4)
		ans.append(12 * n + 6)
		ans.append(12 * n + 9)
	elif j == 6:
		ans.append(12 * n + 2)
		ans.append(12 * n + 3)
		ans.append(12 * n + 4)
		ans.append(12 * n + 8)
		ans.append(12 * n + 9)
		ans.append(12 * n + 10)
	elif j == 7:
		ans.append(12 * n + 2)
		ans.append(12 * n + 3)
		ans.append(12 * n + 4)
		ans.append(12 * n + 6)
		ans.append(12 * n + 8)
		ans.append(12 * n + 9)
		ans.append(12 * n + 10)
	ans = list(map(str, ans))
	print(" ".join(ans))