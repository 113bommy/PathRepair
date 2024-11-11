def fastio():
	import sys
	from io import StringIO 
	from atexit import register
	global input
	sys.stdin = StringIO(sys.stdin.read())
	input = lambda : sys.stdin.readline().rstrip('\r\n')
	sys.stdout = StringIO()
	register(lambda : sys.__stdout__.write(sys.stdout.getvalue()))
fastio()

MOD = 10**9 + 7
I = lambda:list(map(int,input().split()))

a = 'abcdefghijklmnopqrstuvwxyz'
a = a.upper()
n, k = I()
s = list(input() + 'aaa')
ans = 0
if k > 2:
	for i in range(1, n):
		if s[i] == s[i-1]:
			for j in range(k):
				if a[j] != s[i-1] and a[j] != s[i+1]:
					ans += 1
					s[i] = a[j]
					break
			else:
				for j in range(k):
					if a[j] != s[i-1]:
						ans += 1
						s[i] = a[j]
						break
else:
	x = ('AB'*(n//2)) + ('A'*(n%2))
	y = ('BA'*(n//2)) + ('B'*(n%2))
	a1 = 0
	a2 = 0
	for i in range(n):
		if s[i] != x[i]:
			a1 += 1
		if s[i] != y[i]:
			a2 += 1
	ans = min(a1, a2)
	s = [x, y][a1 < a2]
print(ans)
print(''.join(s[:n]))