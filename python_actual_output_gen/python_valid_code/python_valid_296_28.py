
n, t = map(int, input().split())
l = list(map(int, input().split()))

for i in range(n):
	d = 86400 - l[i]
	t -= d
	if t == 0:
		print(i + 1)
		exit()