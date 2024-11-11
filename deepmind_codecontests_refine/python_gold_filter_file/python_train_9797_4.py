import sys

def minp():
	return sys.stdin.readline().strip()

n, k = map(int, minp().split())
kk = 2*k + 1
r = []
if n%kk < k + 1 and n%kk > 0:
	#print('q')
	for i in range(((n%kk)+1)//2,n+1,kk):
		r.append(i)
else:
	for i in range(1+k,n+1,kk):
		r.append(i)
print(len(r))
for i in r:
	print(i, end=' ')