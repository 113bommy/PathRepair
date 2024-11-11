import sys
t = int(sys.stdin.readline())
while t:
	t -= 1
	n, l, r = map(int, sys.stdin.readline().split())
	arr = list(map(int, sys.stdin.readline().split()))
	arr.sort()
	ans, A, B = 0, 0, 0 
	cnt = 0 
	for i in range(n):
		lo, hi = i + 1, n - 1 
		asn = 0 
		while lo <= hi:
			mid = lo + (hi - lo) // 2
			if arr[mid] + arr[i] <= r:
				ans = mid 
				lo = mid + 1
			else:
				hi = mid - 1 
		if ans != 0:
			A += (ans - i)
		ans = 0 
		lo, hi = i + 1, n - 1
		while lo <= hi:
			mid = lo + (hi - lo) // 2 
			if arr[mid] + arr[i] <= l - 1:
				ans = mid 
				lo = mid + 1 
			else:
				hi = mid - 1 
		if ans != 0:
			B += (ans - i)
		cnt += (A - B)
		A, B = 0, 0 
	print(cnt) 