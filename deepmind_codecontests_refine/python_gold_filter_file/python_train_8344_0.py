n, f1, f2, f3, c = list(map(int,input().split()))
mat = [[1,1,1],[1,0,0],[0,1,0]]
final = [[1,0,0],[0,1,0],[0,0,1]]
nn = n - 3
N = 10**9 + 6
def prod(a, b):
	m = [[0,0,0],[0,0,0],[0,0,0]]
	for i in range(3):
		for j in range(3):
			m[i][j] = (a[i][0]*b[0][j] + a[i][1]*b[1][j]+a[i][2]*b[2][j]) % N
	return m
while nn > 0:
	if nn % 2 == 1:
		final = prod(final, mat)
	mat = prod(mat,mat)
	nn //= 2
q = (final[0][0] * 3 + final[0][1] * 2 + final[0][2] * 1) % N
p = q - (n%N) + N
# p to potega c
ef3 = (final[0][0] * 1) % N
ef2 = (final[0][1] * 1) % N
ef1 = (final[0][2] * 1) % N
# print f1^ef1 *f2^ef2*f3^ef3 * c^p
def pot(a,w):
	wyn = 1
	while w > 0:
		if w%2 == 1:
			wyn = (wyn * a) % (N+1)
		a = (a * a) % (N+1)
		w //= 2
	return wyn
l1 = pot(f1, ef1)
l2 = pot(f2, ef2)
l3 = pot(f3, ef3)
l4 = pot(c, p)
c = (l1*l2*l3*l4)%(N+1)
print(c)