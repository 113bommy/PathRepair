#import io, os
#input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

n, k = map(int, input().split())
a = list(map(int, input().split()))
vis = [False]*n
answer = 0
for i in range(n):
	t = 0
	if not vis[i]:
		for j in range(i,n):
			if not vis[j]:
				temp = a[j] - ((j-i)*k)
				x = temp - a[i]
				if x == 0:
					t += 1
					vis[j] = True
				if temp <= 0:
					vis[j] = True
	if t > answer:
		answer = t
		poi = i
		val = a[i]
print(n-answer)

if answer != n:
	for i in range(n):
		x = a[i] - val-((i-poi)*k)
		if x == 0: continue
		elif x>0: print('{} {} {}'.format('-', i+1, x))
		elif x<0: print('{} {} {}'.format('+', i+1, -x))