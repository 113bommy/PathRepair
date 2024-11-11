n = int(input())
a = list(map(int, input().split()))
pref = [0] * (n + 1)
for i in range(n):
	pref[i + 1] = pref[i] + (1 if a[i] == 1 else 0)
suf = [0] * (n + 1)
for i in reversed(range(n)):
	suf[i] = suf[i + 1] + (1 if a[i] == 2 else 0)
dp = [0, 0, 0, 0]
for i in range(n):
	new_dp = [max(dp[i], dp[i - 1]) if i > 0 else dp[i] for i in range(4)]
	if a[i] == 1:
		new_dp[0] += 1
		new_dp[2] += 1
	else:
		new_dp[1] += 1
		new_dp[3] += 1
	dp = new_dp
print(max(max([pref[i] + suf[i] for i in range(n + 1)]), max(dp)))