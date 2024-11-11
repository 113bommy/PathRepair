n = int(input())
d = {}
for i in range(n):
	data = input()
	l = len(data)
	if not l in d:
		d[l] = {}
	for j in data:
		if not j in d[l]:
			d[l][j] = 0
		d[l][j] += 1

for i in range(n):
	data = input()
	l = len(data)
	if not l in d:
		d[l] = {}
	for j in data:
		if not j in d[l]:
			d[l][j] = 0
		d[l][j] -= 1
	
ans = 0
for i in d:
	for j in d[i]:
		if d[i][j] > 0:
			ans += 1
	
print(ans)
