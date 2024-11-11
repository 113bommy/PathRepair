n, k = map(int, input().split(' '))
symbols = 'abcdefghijklmnopqrstuvwxyz'
newPsw = ''
q = 0
fx = lambda q: q + 1
for i in range(n):
	newPsw += symbols[q]
	q = (0 if q == k else fx(q))
print(newPsw)