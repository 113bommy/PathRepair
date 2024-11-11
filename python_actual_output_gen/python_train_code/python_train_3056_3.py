n = int(input())
b, a = [], []
for i in range(n):
	x, y = map(int, input().split())
	b.append(y)
	a.append(x)
c = a[:]
for i in range(n):
	if b[i] in a and a[i] != b[i]:
		for j in range(a.count(b[i])):
			try:
				c.remove(b[i])
			except:
				pass
	elif a[i] == b[i] and a.count(a[i]) > 1:
		for j in range(b.count(b[i])):
			try:
				c.remove(b[i])
			except:
				pass
print(len(c))