n, m = map(int,input().split())
b = []
d = []
for x in range(n):
	if x == 0:
		a,c = map(int,input().split())
		if (a * 60) + c >= m:b.append("0 0")
		d.append((a * 60) + c)
	else:
		a ,c = map(int,input().split())
		if ((a * 60) + c) - d[-1] > (m * 2) + 1:
			f = d[-1] + m + 1
			b.append(str(f // 60) + " " + str((f % 60)))
		d.append((a * 60) + c)
if len(b) == 0:
	f = d[-1] + m + 1
	b.append(str(f // 60) + " " + str((f % 60)))
print(b[0])