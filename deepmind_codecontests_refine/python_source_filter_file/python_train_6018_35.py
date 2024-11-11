S = input()
S = S[::-1]
#print(S)

mod = 10**9+7

dp = [0]*13
dp[0] = 1
for i in range(len(S)-1,-1,-1):
	ch = int(S[i]) if S[i]!='?' else -1
	temp = [0]*13
	for d in range(10):
		if ch!=-1 and ch!=d:
			continue
		for m in range(13):
			temp[(d*10**i+m)%13] += dp[m]
	for m in range(13):
		temp[m] %= mod
	dp = temp
print(dp[5])
