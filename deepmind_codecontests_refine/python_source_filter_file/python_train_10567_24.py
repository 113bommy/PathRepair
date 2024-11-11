s = input();
m = int(input())
for _ in range(m):
	l, r, k = map(int, input().split())
	l -= 1
	r -= 1
	k = k%(r-l+1)
	t = s[l:r+1]
	z = t[::-1]
	y = z[:k]
	s = s[0:l] + y[::-1] + t[:(r-l+1)-k] + s[r+1:]
	print(s)