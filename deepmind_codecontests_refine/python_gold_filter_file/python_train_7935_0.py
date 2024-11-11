t = int(input())
for rep in range(t):
	n = int(input())
	a = list(map(int,input().split()))
	primes = [2,3,5,7,11,13,17,19,23,29,31]
	colarr = [0]*n
	m = 0
	for i in range(11):
		f = 0
		for j in range(n):
			if a[j]%primes[i] == 0 and colarr[j] == 0:
				colarr[j] = m+1
				f = 1
		if f==1:
			m += 1
	print(m)
	print(" ".join(list(map(str,colarr))))