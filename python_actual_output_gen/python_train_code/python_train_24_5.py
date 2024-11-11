n, k = map(int, input().split())
a = [int(i) for i in input().split()]
l = []
for i in a:
	if k % i == 0:
		l.append(i)

print(max(l))