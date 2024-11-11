r = lambda: [*map(int, input().split())]

def c(e,b):
	if a[e-1][b]=='.' and a[e+1][b]=='.' and a[e][b+1]=='.' and a[e][b-1]=='.': return True
	else: return False

n = int(input())
f = True
a = []
b = 0
for i in range(n):
	g = [*input()]
	a.append(g)
	b+= a[i].count('.')
b/= 5
b1 = 0
for i in range (1,n-1):
	for j in range(1,n-1):
		if c(i,j):
			b1+= 1
			a[i][j] = '0'
			a[i-1][j] = '0'
			a[i+1][j] = '0'
			a[i][j+1] = '0'
			a[i][j-1] = '0'
for i in a:
	if '.' in i:
		f = False
		break
if b1==b:
	print('YES')
else:
	print ('NO')