from bisect import *
t = int(input())
for i in range(t):
	d = {}
	a = []
	for i in range(26):
		a.append(0)
	n , m = map(int , input().split(' '))
	s = input()
	l = list(map(int , input().split(' ')))
	l.append(n)
	l.sort()
	for i in range(len(s)):
		x = bisect_right(l , i + 1 , 0 , len(l))
		if(l[x - 1] != i + 1):
			x += 1
		# print("x = " , x)
		a[ord(s[i]) - 97] += len(l) - x + 1
	print(*a)
	# print()
