n = int(input())
s = input()[::1]
m = len(s)

dp = [[-1 for i in range(100)] for j in range(100)]

INF = 1e20

def get(i, j):
	if (dp[i][j] == -1):
		ans = INF
		if (i == 0 and j == 0):
			ans =  0
		elif (j == 0):
			ans =  INF
		else:
			for leng in range(1, 10):
				if (i >= leng):
					num = s[m-i:m-i+leng]
					if (num == "" or int(num) >= n or (num[0] == '0' and len(num) != 1)):
						continue
					num = int(num)
					ans = min(ans, get(i - leng, j - 1) + num * pow(n, j - 1))
				else:
					break
		dp[i][j] = ans
	return dp[i][j]

ans = INF
for i in range(1, 20):
	dp = [[-1 for i in range(100)] for j in range(100)]
	ans = min(ans, get(m, i))
print(ans)