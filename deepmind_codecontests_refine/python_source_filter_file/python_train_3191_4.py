n = int(input())
A = []
for i in range(n):
	s = input()
	h = s[:2]
	m = s[3:]
	A.append((int(h), int(m)))
md = -12341234
A = sorted(A)
for i in range(n - 1):
	a, b = A[i]

	c, d = A[i + 1]
	g = (c - a) * 60
	if(b > d):
		g += 60 - b + d
		g -= 60
	else:
		g += d - b
	if(g > md):
		md = g
a, b = A[0]
c, d = A[n - 1]
g = (24 - c + a)*60
g += 60 - d + b
if(g > md):
	md = g
md -= 1
if(md//60 < 10):
    print('0', sep = '', end = '');
print(md//60, ':', sep ='', end = '')
if(md % 60 < 10):
    print('0', sep = '', end = '');
print(md % 60)
