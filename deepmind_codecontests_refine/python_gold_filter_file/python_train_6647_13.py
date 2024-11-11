n = int(input())
a = list(map(int, input().split()))
if sum(a) % (n * (n + 1) // 2) != 0:
	print("NO")
else:
	k = sum(a) // (n * (n + 1) // 2)
	ok = True
	for i in range(n - 1):
		if (a[i] + k) % n != a[i + 1] % n or a[i] + k < a[i + 1]:
			ok = False
			break
	if (a[-1] + k) % n != a[0] % n or a[-1] + k < a[0]:
		ok = False

	if ok:
		print("YES")
	else:
		print("NO")