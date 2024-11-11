def fastio():
	import sys
	from io import StringIO 
	from atexit import register
	global input
	sys.stdin = StringIO(sys.stdin.read())
	input = lambda : sys.stdin.readline().rstrip('\r\n')
	sys.stdout = StringIO()
	register(lambda : sys.__stdout__.write(sys.stdout.getvalue()))
fastio()

MOD = 10**9 + 7
I = lambda:list(map(int,input().split()))

n, k = I()
l = I()
p = []
s = sum(l[:k])
dp = [[0, 0] for i in range(n+10)]
dp[k-1][1] = dp[k-1][0] = s
a = [0]*n
a[0] = l[0]
for i in range(n):
	a[i] = a[i-1] + l[i]
for i in range(k, n):
	s -= l[i-k]
	s += l[i]
	dp[i][1] = max(dp[i-k][0] + s, dp[i-1][1])
	dp[i][0] = max(s, dp[i-1][0])

i = n-1
f = s = -1
# print(dp)
while i >= 1:
	if dp[i-1][1] == dp[i][1] or f != -1 and dp[i-1][0] == dp[i][0]:
		i -= 1
	else:
		if f == -1:
			f = i-k+1
		elif s == -1:
			s = i-k+1
		i -= k
		# print(i)
print(s+1, f+1)