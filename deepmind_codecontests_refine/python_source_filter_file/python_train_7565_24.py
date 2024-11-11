n = int(input())
s = input()
d = n
l = []
while d > 1:
	if n % d == 0:
		l.append(d)
	d -= 1
for i in l[::-1]:
	s = s[:i][::-1] + s[i:]
	print(s)