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
 
n, = I()
l = I()
if n == 1:
	print(l[0]**2)
	exit()
l.sort(reverse = True)
h = sum(l[:n//2+ n%2])

print((h**2 + (sum(l)-h)**2))