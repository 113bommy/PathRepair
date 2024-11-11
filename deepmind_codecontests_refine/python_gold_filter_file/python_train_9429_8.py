n = int(input())
a = sorted(list(map(int, input().split())))
for i in range(1, n - 1):
	if a[i] + a[i - 1]> a[i + 1]:
		exit(print("YES"))
print("NO")