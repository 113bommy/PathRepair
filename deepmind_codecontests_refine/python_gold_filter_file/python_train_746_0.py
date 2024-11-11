import os, sys
try: fin = open('in')
except: fin = sys.stdin
input = fin.readline
n, k = map(int, input().split())
l, h = 0, 0
for i in range(1, n + 1):
	l += i
	h += max(i, n - i + 1)
if k < l:
	print (-1)
elif k > h:
	os.write(1, ('{}\n{}\n{}'.format(h, ' '.join(map(str, range(1, n + 1))), ' '.join(map(str, range(n, 0, -1))))).encode())
else:
	d = k - l
	r = n
	ans = [i for i in range(n + 1)]
	for i in range(1, n + 1):
		p = min(r - i, d)
		ans[i], ans[i + p] = ans[i + p], ans[i]
		d -= p
		r -= 1
		if d == 0: break
	os.write(1, ('{}\n{}\n{}'.format(k, ' '.join(map(str, range(1, n + 1))), ' '.join(map(str, ans[1:])))).encode())