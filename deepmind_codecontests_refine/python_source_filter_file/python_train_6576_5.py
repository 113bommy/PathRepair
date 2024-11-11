for _ in range(int(input())):
	s, t, p = input(), input(), input()

	tt = {}
	st = {}
	pt = {}

	dp = [[0] * (len(s) + 1) for i in range(len(t) + 1)]
	for i in range(1, len(t) + 1):
		for j in range(1, len(s) + 1):
			if t[i - 1] == s[j - 1]:
				dp[i][j] = dp[i - 1][j - 1] + 1
			else:
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j])


	if dp[len(t)][len(s)] < len(s):
		print('NO')
		break

	ans = 'YES'
	from string import ascii_lowercase

	for i in ascii_lowercase:
		tt[i] = 0
		st[i] = 0
		pt[i] = 0

	for i in s:
		st[i] += 1
	for i in p:
		pt[i] += 1
	for i in t:
		tt[i] += 1

	for i in ascii_lowercase:
		if st[i] > tt[i] or tt[i] - st[i] > pt[i]:
			ans = 'NO'
			break

	print(ans)