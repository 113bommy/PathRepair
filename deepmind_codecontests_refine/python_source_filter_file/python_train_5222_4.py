#codeforces1162A
gi = lambda : list(map(int,input().strip().split()))
n, h, m = gi()
l = [h]*(n + 1)
l[0] = 0
for k in range(m):
	x,y,v = gi()
	for j in range(x,y + 1):
		l[j] = min(v, h)
print(sum([e*e for e in l]))