import sys

window = set()

n, k, q = [int(x) for x in input().split()]
arr = [int(x) for x in input().split()]

for i in range(q):
	a, b = [int(x) for x in input().split()]
	if (a == 1):
		if (len(window) < k):
			window.add(arr[b - 1])
		else:
			window.add(arr[b - 1])
			m = min(window)
			window.remove(m)
	else:
		print("YES" if arr[b - 1] in window else "NO")

