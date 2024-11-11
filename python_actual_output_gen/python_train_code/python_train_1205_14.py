s, k = input().split()
k = int(k)

n = len(s)
z = 0
c = 0
for i in range(n-1, -1, -1):
	if (k == z):
		break
	if (s[i] != "0"):
		c += 1
	else:
		z += 1
if ((z+c) <= k):
	print(n-1)
else:
	print(c)