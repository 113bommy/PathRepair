def read():
	return [int(i) for i in input().split(" ")]
N = int(input())
T = read()
A = read()
t = [(i != j, i) for i, j in zip(T, [None] + T)]
a = [(i != j, i) for i, j in zip(A, (A + [None])[1:])]
P = 1
for p, q in zip(t, a):
	if(p[0]):
		if(q[0]):
			if(p[1] != q[1]):
				print(0)
				exit()
		elif(q[1] < p[1]):
			print(0)
			exit()
	elif(q[0]):
		if(p[1] < q[1]):
			print(0)
			exit()
	else:
		P *= min(p[1], q[1]) % (10 ** 9 + 7)
print(P)
