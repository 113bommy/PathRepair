def check(val):
	return b[m * k - 1] <= val

n, m, k = map(int, input().split())

i = 0
a = []
b = []

for x in input().split():
	a.append((int(x), i))
	b.append((int(x), i))
	i += 1

b.sort()
b.reverse()


res = 0
p = []
cnt = 0


for i in range(n):
	if check(a[i]):
		cnt += 1
		res += a[i][0]
	if cnt == m + 1:
		p.append(i)
		cnt = 1

print(res)
for x in p:
	print(x, end=' ')
