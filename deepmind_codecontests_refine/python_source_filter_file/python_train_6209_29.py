a, b = map(str,input().split())
k = []
for i in range(1, len(a)):
	s = ''
	for j in range(1, len(b)):
		k += [a[0:i] + b[0:j]]
k.sort()
print(k[0])
