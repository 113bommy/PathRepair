n, m = map(str, input().split())
x = list(m)
x.reverse()
s = ''
for el in x:
	s += el
print((int(n) + int(m)))