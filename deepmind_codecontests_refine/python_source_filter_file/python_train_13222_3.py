def insertionSort(A,n,g,cnt):
	for i in range(g,n):
		v = A[i]
		j = i - g
		while j >= 0 and A[j] > v:
			A[j+g] = A[j]
			j = j - g
			cnt += 1
		A[j+g] = v
	return A,cnt

def shellSort(A,n):
	cnt = 0
	G = [1]
	while G[-1] <= n:
		G.append(G[-1]*3 + 1)
	G = G[::-1]
	m = len(G)
	for g in G:
		A,cnt = insertionSort(A,n,g,cnt)
	return A,m,G,cnt

if __name__ == '__main__':
	
	n = int(input())
	A = []
	[A.append(int(input())) for i in range(n)]
	
	'''
	data = [int(d) for d in data.split('\n')]
	n = data.pop(0)
	A = data[:]
	'''
	
	A,m,G,cnt = shellSort(A,n)
	print(m)
	print(' '.join([str(i) for i in G]))
	print(cnt)
	[print(a) for a in A]