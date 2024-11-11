n, p = map(int, input().split())
s = input().rstrip()

p = min(p, n - p + 1)
Count = 0
M = l = r = X = p
for i in range(0, n // 4):
	C = min(abs(ord(s[i]) - ord(s[-i - 1])), abs(ord('z') - max(ord(s[i]), ord(s[-i - 1])) + min(ord(s[i]), ord(s[-i - 1])) - ord('a') + 1) % 26)
	if C > 0:
		if (i + 1 < p):
			if (M == p):
				M = i + 1
			l = i + 1
		elif (i + 1 > p and r == p):
			r = i + 1
		X = i + 1
	Count += C
print(Count + min(abs(X - p) + X - M, X + p - M * 2))
