def solve(n, m, a, p):
	def is_sorted(alist):
		for i in range(len(alist)-2):
			if alist[i] > alist[i+1]:
				return False
		return True

	is_continue = True
	while is_continue:
		num_ops = 0
		for pos in p:
			if a[pos-1] > a[pos]:
				num_ops += 1
				a[pos-1], a[pos] = a[pos], a[pos-1]

		if is_sorted(a):
			return True
		else:
			if num_ops == 0:
				return False



t = int(input())
for _ in range(t):
	n, m = map(int, input().split())
	a = list(map(int, input().split()))
	p = list(map(int, input().split()))
	result = "YES" if solve(n,m,a,p) else "NO"
	print(result)