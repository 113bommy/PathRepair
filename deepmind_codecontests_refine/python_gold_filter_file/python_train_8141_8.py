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

IND = 10 ** 20
MOD = 10**9 + 7
I = lambda:list(map(int,input().split()))
from math import gcd
from collections import defaultdict as dd

t, = I()
while t:
	t -= 1
	s = input() + '############'
	a = []
	i = 0
	while i < len(s) - 5:
		if s[i: i + 5] == 'twone':
			a.append(i + 1 + 2)
			i = i + 5
		elif s[i: i + 3] == 'one':
			a.append(i + 2)
			i += 2
		elif s[i: i + 3] == 'two':
			a.append(i + 2)
			i += 2
		else:
			i += 1

	print(len(a))
	print(*a)