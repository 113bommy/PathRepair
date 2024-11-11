n = int(input())
l, u = 0, 10**18
b = list(map(int, input().split()))
a = [0 for i in range(n)]
for i in range(n // 2):
	a[i] = max(l, b[i] - u)
	a[-i - 1] = b[i] - a[i]
	l, u = a[i], a[-i - 1]
for i in a:
    print(i, end = ' ')