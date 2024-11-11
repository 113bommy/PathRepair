n = int(input())
a, s = [], input()
for i in range(n):
	if s[i] == '1':
		a.append(i)
if len(a) == 0:
	print('No')
elif a[1] > 1 or a[-1] < n - 2:
		print('No')
else:
	for i in range(1, len(a)):
		if not 1 < a[i] - a[i - 1] < 4:
			print('No')
			exit(0)
	print('Yes')