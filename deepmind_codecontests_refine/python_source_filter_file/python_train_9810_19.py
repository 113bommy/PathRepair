q = int(input())
for rwer in range(q):
	n = int(input())
	s = input()
	if n == 1:
		print(1)
		print(s)
	else:
		for k in range(1,n+1):
			if k == 1:
				bestk = 1
				bescik = s
			else:
				if (k-n)%2 == 0:
					dod = s[:(k-1)][::-1]
				else:
					dod = s[:(k-1)]
				slowo = s[k-1:n] + dod
				if slowo < bescik:
					bescik = slowo
					bestk = k
		print(bescik)
		print(bestk)