import sys
sys.setrecursionlimit(1000000)
x = int(input())
m = [[] for i in range(x)]
for i in range(x - 1):
	l = int(input())
	m[l - 1] += [i + 2]
for i in range(x):
	if len(m[i]) != 0:
		m[i] += [len(m[i])]
	else:
		m[i] += [-10000]
k = 1
f = 0
def dfs(k,f):
	if m[k - 1][-1] > 2:
		if f != 0:
			m[f][-1] -= 1
		for i in range(m[k - 1][-1]):
			dfs(m[k-1][i], (k))
	elif m[k - 1][-1] == 1 or m[k - 1][-1] == 2:
		m[f][-1] -= 1
	return 0
dfs(k,f)
t = 0
for i in range(x):
	if m[i][-1] < 3 and m[i][-1] != -10000:
		print('No')
		t = 1
		break
if t == 0:
	print('Yes')
