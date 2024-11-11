a, b = map(str,input().split())
k = []
for i in range(1, len(a) + 1):
	s = ''
	for j in range(1, len(b) + 1):
		k += [a[0:i] + b[0:j]]
k.sort()
print(k[0])
