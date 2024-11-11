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

n, m = I()
p = [0]*200
for i in range(200):
	p[i] = i

def find(u):
	if p[u] == u:
		return u
	else:
		p[u] = find(p[u])
	return p[u]

def join(u, v):
	x = find(u)
	y = find(v)
	if x != y:
		p[x] = y

st = set()
count = 0
for i in range(n):
	t = I()
	k, l = t[0], t[1:]
	if k == 0:
		count += 1
	for i in l:
		join(l[0], i)
		st.add(i)

ans = 0
# print(p[1:m+1])
v = [0]*200
s = set()
for i in st:
	s.add(find(i))
print(len(s) - 1 + count)