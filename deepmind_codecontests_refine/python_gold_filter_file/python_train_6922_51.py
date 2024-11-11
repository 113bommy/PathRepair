na, nb = map(int, input().split())
p , q = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
if a[p-1] < b[nb - q]:
	print('YES')
else:
	print('NO')