'''input
15
0 16
6 15
8 2
8 6
8 7
10 1
10 1
10 3
10 12
13 5
14 16
14 16
14 16
14 16
14 16
'''
n = int(input())
s, r = input(), 1
max_r = 0
for _ in range(n-1):
	x = input()
	if x == s:
		r += 1
	else:
		if r > max_r:
			max_r = r
		s, r = x, 1
	if r > max_r:
		max_r = r

print(max_r)





