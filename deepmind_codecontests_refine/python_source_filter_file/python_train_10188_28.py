n = int(input())
p = list(map(int, input().split()))
a = list(range(20000, (n + 1) * 20000, 20000))
b = a[::-1]
for i in range(len(p)):
	a[p[i] - 1] -= n - i
for i in a:
	print(i, end=" ")
print()
for i in b:
	print(i, end=" ")
print()