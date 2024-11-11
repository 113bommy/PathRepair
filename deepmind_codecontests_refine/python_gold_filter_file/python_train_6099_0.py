
def main():
	t = input()
	p = input()
	n = len(t)
	pos = list(map(lambda x: int(x) - 1, input().split()))

	def f(ind):
		was = [0 for _ in range(n)]
		
		for i in range(ind + 1):
			was[pos[i]] = 1	

		pattern_pos = 0

		for i, ch in enumerate(t):
			if was[i] == 0 and pattern_pos < len(p) and ch == p[pattern_pos]:
				pattern_pos += 1

		return pattern_pos == len(p)	


	l,r = 0, n

	while l < r - 1:
		mid = (l + r) // 2
		if f(mid):
			l = mid
		else:
			r = mid

	while l >= 0 and not f(l):
		l -= 1		
	while l + 1 < n and f(l + 1):
		l += 1

	print(l + 1)


if __name__ == "__main__":
	main()