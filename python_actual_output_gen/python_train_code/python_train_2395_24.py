na, nb = map(int, input().split())
p , q = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
if a[p-1] < b[0]:
	print('YES')
else:
	print('NO')