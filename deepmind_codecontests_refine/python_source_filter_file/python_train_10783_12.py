def f(n, m, da):
	if (da <= m):
		return n - da
	else:
		da -= m
		end_m = n - m
		return end_m - (da * (da + 1)) / 2

def main():
	n, m = map(int, input().split())
	if (f(n, m, 1) > 0):
		l = 1;
		r = 10**18
		while (l + 1 < r):
			me = (l + r ) // 2
			if (f(n,m,me) > 0):
				l = me
			else:
				r = me
		print(r)
	else:
		print(1)

main()