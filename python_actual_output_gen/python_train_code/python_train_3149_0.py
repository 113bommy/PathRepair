n = int(input())
l = list(map(int, input().split()))
l = [min(i, -i-1) for i in l]
count = sum(x < 0 for x in l)
if count % 2 == 0:
	print(*l)
else:
	f = lambda i: l[i]
	i = max(range(len(l)), key=f)
	l[i] = - l[i] - 1
	print(*l)