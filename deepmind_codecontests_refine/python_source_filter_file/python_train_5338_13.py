n = int(input())
a = list(map(int, input().split()))
a.reverse()
ch = 0
for i in range(2, n, 2):
	ch += 1
	a[i], a[i - 1] = a[i - 1], a[i]
print(ch)
print(*a)
