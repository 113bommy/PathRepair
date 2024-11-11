a = [int(i) for i in input().split()]
n = a[0]
m = a[1]
k = a[2]
s = []
for _ in range(k):
	s.append([int(i) for i in input().split()])
f = []
for _ in range(k):
	f.append([int(i) for i in input().split()])

ans = []

ans.append((n - 1) * 'L')
ans.append((m - 1) * 'U')
for i in range(m - 1):
	if i != 0:
		ans.append('D')
	if i % 2 == 0:
		ans.append((n - 1) * 'R')
	else:
		ans.append((n - 1) * 'L')

ans = ''.join(ans)
print(len(ans))
print(ans)







