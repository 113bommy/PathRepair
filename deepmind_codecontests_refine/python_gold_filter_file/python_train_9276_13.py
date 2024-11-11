n = int(input())
l = [[int(i) for i in input().split()] for i in range(n)]

f = []
for i in l[0][1:]:
	m = [i for j in range(1,n) if i in l[j][1:]]
	if len(m) == n-1:
		f += m

for i in set(f):
	print(i, end=' ')
		