import sys
 
def pro():
	return sys.stdin.readline().strip()
 
def rop():
	return map(int, pro().split())
 
def main():
	s = list(rop())
	a = list(rop())
	q = list(rop())
	o = list(rop())
	p = -1
	t = (1e100, -1, -1)
	for i in range(s[1]):
		while not((p == - 1 or s[2] * q[i] - s[3] * a[p] >= 0)
			and (p + 1 == s[0] or s[2] * q[i] - s[3] * a[p+1] < 0)):
			p += 1
		if p != -1:
			t = min(t, (o[i] + (s[2] ** 2 + a[p] ** 2) ** 0.5 + ((s[3] - s[2]) ** 2 + (q[i] - a[p]) ** 2) ** 0.5, p, i))
		if p + 1 != s[0]:
			t = min(t, (o[i] + (s[2] ** 2  + a[p + 1] ** 2) ** 0.5 + ((s[3] - s[2]) ** 2 + (q[i] - a[p + 1]) ** 2) ** 0.5, p + 1, i))
	print(t[1] + 1, t[2] + 1)
 
main()