n, m = map(int, input().split())
li = list(map(int, input().split()))

count = 0
for i in range(n):
	if li[i] % m == 0:
		count = count + (li[i] // m)
	else:
		count = count + (li[i] // m) + 1

if (count % m == 0):
	print(count // 2)
else:
	print((count // 2) + 1)