import re
n = int(input())
a = []
for i in range(n):
	a.append(input())
	a[-1] = re.sub(r'[0]', ' ', a[-1]).split()
	a[-1].sort()
	a[-1].reverse()
print(a)
b = []
for i in range(n):
	if len(a[-1]) == 0:
		b.append([0])
	else:
		count = 0
		for j in range(0, len(a[i]), 2):
			count += len(a[i][j])
		b.append(count)

for i in b:
	print(i)

