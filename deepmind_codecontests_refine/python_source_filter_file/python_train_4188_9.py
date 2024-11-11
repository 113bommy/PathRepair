n = int(input())
for i in range(n):
	t = int(input())
	l = list(map(int,input().split()))
	sum1 = 0
	sum2 = 0
	z = float("-inf")
	flag = 0
	flag1 = 0
	dp = [0 for i in range(t+1)]
	s = 0
	for j in range(t):
		s = s + l[j]
		if l[j] < 0:
			flag1 = 1
		dp[j+1] = max(dp[j] + l[j],l[j])
	if flag1 == 0:
		print("YES")
		continue
	# print(dp)
	for j in range(1,len(dp)):
		if j == t and dp[t] == s and flag1 == 0:
			break
		elif j == t and dp[t] > s:
			flag = 1
			print("NO")
			exit()
		elif dp[j] >= s and j < t or dp[j] == 0:
			print("NO")
			flag = 1
			break
	if flag == 0:
		print("YES")