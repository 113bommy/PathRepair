v = int(input())
A = list(map(int, input().split()))
if v < min(A):
	print(-1)
else:
	basic = 1
	for i in range(9):
		if A[i] <= A[basic - 1]:
			basic = i + 1
	ans = [basic] * (v // A[basic - 1])
	ost = v % A[basic - 1]
	now = 0
	find = True
	while find:
		find = False
		for i in range(8, basic, -1):
			if A[i] <= A[basic - 1] + ost:
				ans[now] = i + 1
				ost = ost + A[basic - 1] - A[i]
				now += 1
				find = True
				break
	print("".join(list(map(str, ans))))