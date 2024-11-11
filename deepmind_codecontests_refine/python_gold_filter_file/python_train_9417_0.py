n = int(input())
a = list(set(map(int,input().split())))
prev = [0] * 2000001
for x in a:
	prev[x] = x
latest = 0
for x in range(2000001):
	if prev[x] == x:
		prev[x] = latest
		latest = x
	else:
		prev[x] = latest
ans = 0	
for x in a:
	for j in range(2 * x, 2000001, x):
		ans = max(ans, prev[j] % x)
print (ans)