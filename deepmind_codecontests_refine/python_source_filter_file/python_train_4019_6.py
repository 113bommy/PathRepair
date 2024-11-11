'''input
4 1
0 2
0 3
3 5
0 6
'''
n, f = map(int, input().split())
if f == 0:
	s = 0
	for _ in range(n):
		k, l = map(int, input().split())
		s += k
	print(s)
else:
	s = 0
	d = []
	for _ in range(n):
		k, l = map(int, input().split())
		s += min(k, l)
		d.append(min(2*k, l) - min(k, l))
	print(s + sum(sorted(d)[-f:]) if f > 0 else s)
