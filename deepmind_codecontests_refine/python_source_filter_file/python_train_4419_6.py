n = int(input())
s = []
for i in range(n):
	c, p = (map(int, input().split()))
	s.append((p, c, i))
z = s[:]
k = int(input())
m = list(map(int, input().split()))
s.sort()
s.reverse()
answ = 0
summ = 0
sisok = []
f = "lopata"
for i in range(n):
	price = s[i][0]
	col = s[i][1]
	index = s[i][2]
	zn = 100000001
	uk = -1
	for j in range(k):
		if col <= m[j] < zn:
			uk = j
			zn = m[j]
	if uk != -1:
		m[uk] = 0
		sisok.append((index + 1, uk + 1))
		summ += c
print(len(sisok), summ)
for x in sisok:
	print(*x)
