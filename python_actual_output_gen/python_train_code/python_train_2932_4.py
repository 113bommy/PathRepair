n, *a = map(int, open(0).read().split())
M = max(a)
mcnt = a.count(M - 1)
Mcnt = a.count(M)
if Mcnt + mcnt == n:
	if mcnt == 0:
		if 2 * Mcnt <= n or M == n - 1:
			print("Yes")
			exit()
	else:
		if 0 < 2 * (M - mcnt) <= n - mcnt:
			print("Yes")
			exit()
print("No")