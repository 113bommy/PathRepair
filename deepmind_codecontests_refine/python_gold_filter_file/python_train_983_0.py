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

n, l, x, y = I()
a = I()
s = set(a)
f = 0
for i in range(n):
	if a[i] + x in s:
		break
else:
	f = 1
for i in range(n):
	if a[i] + y in s:
		break
else:
	f += 2
if f == 1:
	print(1)
	print(x)
elif f == 2:
	print(1)
	print(y)
elif f == 0:
	print(0)
else:
	for i in range(n):
		k = a[i] + x
		if 0 <= k <= l and ((k - y >= 0 and (k-y) in s) or ((k+y) <= l and (k+y) in s)):
			print(1)
			print(k)
			exit()
		k = a[i] - x
		if 0 <= k <= l and ((k - y >= 0 and (k-y) in s) or ((k+y) <= l and (k+y) in s)):
			print(1)
			print(k)
			exit()
	for i in range(n):
		k = a[i] + y
		if 0 <= k <= l and (k - x >= 0 and (k-x) in s or (k+x) <= l and (k+x) in s):
			print(1)
			print(k)
			break
		k = a[i] - y
		if 0 <= k <= l and (k - x >= 0 and (k-x) in s or (k+x) <= l and (k+x) in s):
			print(1)
			print(k)
			break
	else:
		print(2)
		print(x, y)
