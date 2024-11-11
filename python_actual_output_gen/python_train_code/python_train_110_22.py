n, x, y = map(int, input().split())
st = input()
x = n - x
y = n - y - 1
kol = 0
for i in range(x, y):
	if st[i] == "1":
		kol += 1
		print(st[i], i)
if st[y] == "0":
	kol += 1
	print(st[y], y)
for i in range(y + 1, n):
	if st[i] == "1":
		kol += 1
		print(st[i], i)
print(kol)
