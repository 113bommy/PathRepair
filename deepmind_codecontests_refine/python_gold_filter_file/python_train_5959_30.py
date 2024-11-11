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

ans.append((n - 1) * 'U')
ans.append((m - 1) * 'L')
for i in range(n):
	if i != 0:
		ans.append('D')
	if i % 2 == 0:
		ans.append((m - 1) * 'R')
	else:
		ans.append((m - 1) * 'L')

ans = ''.join(ans)
print(len(ans))
print(ans)







