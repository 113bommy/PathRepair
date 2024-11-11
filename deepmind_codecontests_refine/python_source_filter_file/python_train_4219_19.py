n = int(input())
m = int(input())
l = []
for i in range(n):
	l.append(int(input()))
l = sorted(l)[::-1]
cur = 0
for i in range(n):
	cur += l[i]
	if cur > m:
		print(i + 1)
		exit(0)
