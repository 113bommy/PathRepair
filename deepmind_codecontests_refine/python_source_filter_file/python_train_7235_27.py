n = int(input())
a = list(map(int, input().split()))
res = a[0]
for i in range(1, n):
	res += abs(a[i] - a[i - 1])
print(res)
