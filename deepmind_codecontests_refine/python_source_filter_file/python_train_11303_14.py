import math

def binpow(x, y):
	ret = 1
	while y > 0:
		if y % 2 == 1:
			ret *= x
		x *= x
		y //= 2
	return ret

                   

n = int(input())
k = input()       
dp = [[-1 for i in range(100)] for j in range(100)]
#dp[i][j] = min(i, j)
dp[len(k)][0] = 0;
tmp = 0
for i in range(len(k), -1, -1):
	for j in range(1, len(k) + 1):
		tmp = 0
		for s in range(i, len(k)):
			tmp *= 10
			tmp += (ord(k[s]) - ord('0'));
			if tmp > n:
				break
			if dp[s + 1][j - 1] != -1 and dp[i][j] == -1 or dp[s + 1][j - 1] + tmp * binpow(n, j - 1) < dp[i][j]:
				dp[i][j] = dp[s + 1][j - 1] + tmp * binpow(n, j - 1); 		 
			if s == i and k[s] == '0':
				break
			

#print(dp)
ans = 10 ** 20
for i in range(1, len(k) + 1):
	if dp[0][i] != -1:
		ans = min(ans, dp[0][i])
print(ans)